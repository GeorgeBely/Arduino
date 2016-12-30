#include <Wire.h>
#include <EEPROM.h>
#include "TM1637.h"
#include <SoftwareSerial.h>

/** Устанавливаем максимальное колличество секунд, при которых свет будет гореть без наличия движения */
#define MAX_SEK_USE_LED_COUNT 60

/** Номера пинов Arduino, к которым подключается светодиодный индикатор */
#define DISPLAY_CLK_PIN 12
#define DISPLAY_DIO_PIN 13

/** Номер пина Arduino, к которому подключено реле */
#define RELAY_PIN 12

/** Номер пина к которому подключён датчик движения */
#define MOVE_SENSOR_PIN 3

/**
 * Для работы с микросхемой часов и индикатором мы используем библиотеки
 * Классы TM1637 и DS1307 объявлены именно в них
 */
TM1637 display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);

/** заводим Serial-соединение с GPRS-Shield на 7 и 8 цифровых входах */
SoftwareSerial gprsSerial(7, 8);

/** Переменная хранит время оставшиеся до отключения света */
double useLedTime = 0;

/** Переменная хранит значение, была ли отправлена СМС. Это нужно, чтобы  СМС отправялась только 1 раз наличии движения */
boolean isSendSMS = false;

/** В строке currStr будем хранить текущую строку, которую передает нам плата */
String currStr = "";

/** Переменная принимает значение True, если текущая строка является сообщением */
boolean isStringMessage = false;

void setup() {
    //Включаем и настраиваем индикатор
    display.set();
    display.init();

    // GPRS Shield общается по умолчанию на скорости 19200 бод
    gprsSerial.begin(19200);

    // Настраиваем приём сообщений с других устройств
    // Между командами даём время на их обработку
    gprsSerial.print("AT+CMGF=1\r");
    delay(300);
    gprsSerial.print("AT+IFC=1, 1\r");
    delay(300);
    gprsSerial.print("AT+CPBS=\"SM\"\r");
    delay(300);
    gprsSerial.print("AT+CNMI=1,2,2,1,0\r");
    delay(300);
    gprsSerial.println("AT+CLIP=1");
    delay(500);
    
    //Запускаем arduino на порте 9600, для общения с компьютером
    Serial.begin(9600);

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(MOVE_SENSOR_PIN, INPUT);
}

void loop() {
    if (monitoringGSM())
        return;

    boolean haveMove = isMoveEnable(MOVE_SENSOR_PIN);

    if (haveMove) {
        digitalWrite(RELAY_PIN, false);
        useLedTime = MAX_SEK_USE_LED_COUNT;

        if (!isSendSMS) {
            sendSMS("open door!", "+79507775731");
            isSendSMS = true;
        }
    } else {
        if (useLedTime <= 0) {
            digitalWrite(RELAY_PIN, true);
        } else if (useLedTime <= 0.1) {
            useLedTime -= 0.1;
            isSendSMS = false;
        } else {
            useLedTime -= 0.1;
            setDisplayValue(useLedTime * 10, false);
        }
    }
  
    delay(100);
}

/**
 * Функция определяет наличие движения с помощью датчика движения
 *
 * @param moveSensorPin - намер пина, к которому подключён датчик движения
 * prevState - переменная, которая хранит предыдущее значение наличия движения.
 *
 * @return {true}, если датчик зафиксировал движение
 */
int prevState = LOW;
boolean isMoveEnable(int moveSensorPin) {
    boolean val = digitalRead(moveSensorPin);
    if (val != prevState) {
        prevState = val;
        return true;
    }
    return false;
}

/**
 * Функция отображает переданное число на светодиодном индикаторе
 *
 * @param value    - число, которое нужно отобразить (4 значное или меньше)
 * @param usePoint - если {true}, то отображать двоеточие между числами
 */
void setDisplayValue(int value, boolean usePoint) {
    //Значения для отображения на каждом из 4 разрядов
    int8_t disp[4];
    disp[0] = disp[1] = disp[2] = disp[3] = 0;

    int res = value;
    int i = 3;
    while (res > 0 && i >= 0) {
        disp[i] = res % 10;
        res = res / 10;
        i--;
    }

    display.display(disp);
    display.point(usePoint);
}

/**
 * Функция опрашивает GSM модуль на наличие входящего звонка или СМС.
 * При их наличии реагирует должным образом.
 * Для ответа используется функция answerToCall()
 * Для прочтения СМС используется функция readSMS()
 */
void monitoringGSM() {
    touch();

    if (!gprsSerial.available())
        return;

    // Считываем очередной символ с платы
    char currSymbol = gprsSerial.read();

    if ('\r' == currSymbol) {
        if (currStr.startsWith("+CMT")) {
            //если текущая строка начинается с "+CMT",
            //то следующая строка является сообщением
            isStringMessage = true;
        } else if (isStringMessage) {
            readSMS(currStr);
            isStringMessage = false;
        } else if (currStr == "RING") {
            currStr = "";
            return;
        } else if (currStr.startsWith("+CLIP")) {
            // Получен символ перевода строки, это значит, что текущее
            // сообщение от платы завершено и мы можем на него отреагировать.
            // Если текущая строка - это RING, то значит, нам кто-то звонит
            answerToCall(currStr.substring(12, 24));
        }
        currStr = "";
    } else if (currSymbol != '\n') {
        // Дополняем текущую команду новым сиволом
        // При этом игнорируем второй символ в последовательности переноса
        // строки: \r\n
        currStr += String(currSymbol);
    }
}

/**
 * Ответ на входящий звонок
 */
void answerToCall(String number) {
    lcdPrint("incoming call", 0);
    lcdPrint(number, 1);

    if (number == "+79507775731")
        gprsSerial.println("ATA");
    else
        gprsSerial.println("AT+CHUP");
}

/**
 * Cразу после вызова функции начинаем звонить по заданному номеру
 *
 * @param number - номер телефона в формате "+79XXXXXXXXX"
 */
void callTo(String number) {
    lcdPrint("call to", 0);
    lcdPrint(number, 1);

    gprsSerial.print("ATD + ");
    gprsSerial.print(number);
    gprsSerial.println(";");
}

/**
 * Разбираем СМС.
 *
 * @param message - текст сообщения
 */
void readSMS(String message) {
    Serial.println(message);

    // Пересылаем полученное сообщение
    sendSMS(message, "+79507775731");
}

/**
 * Отправляем СМС сообщение на указаный номер.
 *
 * @param message - текст сообщения
 * @param number - номер телефона в формате "+79XXXXXXXXX"
 */
void sendSMS(String message, String number) {
    // Устанавливает текстовый режим для SMS-сообщений
    gprsSerial.print("AT+CMGF=1\r");
    delay(100); // даём время на усваивание команды

    // Устанавливаем адресата: телефонный номер в формате "+79XXXXXXXXX"
    gprsSerial.print("AT + CMGS = \"");
    gprsSerial.print(number);
    gprsSerial.println("\"");
    delay(100);

    // Пишем текст сообщения
    gprsSerial.println(message);
    delay(1000);

    // Отправляем Ctrl+Z, обозначая, что сообщение готово
    gprsSerial.println((char)26);
}

/**
 * Функция провоцирует поддержание коммуникации с платой даже если
 * та была перезагружена без перезагрузки Arduino
 */
int updateTime = 0;
void touch() {
    if (millis() >= updateTime) {
        gprsSerial.println("AT");
        updateTime += 5000;
    }
}