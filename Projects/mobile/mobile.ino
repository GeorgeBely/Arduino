#include "Keypad.h"
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

#define ROWS 4
#define COLS 4

/** С помощью этой переменной будем отрисовывать данные на дисплей */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

/** заводим Serial-соединение с GPRS-Shield на 7 и 8 цифровых входах */
SoftwareSerial gprsSerial(7, 8);

/** Задаём символы соответствующие кнопкам клавиатуры */
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

/** Задаём соответствыя, к каким пинам подключена строка. Можно использовать как аналоговые пины, так и цифровые. */
byte rowPins[ROWS] = {A5, A4, A3, A2};

/** Задаём соответствыя, к каким пинам подключён столбец. Можно использовать как аналоговые пины, так и цифровые. */
byte colPins[COLS] = {A1, A0, 6};

/** С помощью этой переменной будем получать и обрабатывать данные с кейпада */
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/** Строку strKeypad используем для набора номера телефона */
String strKeypad = "";

/** В строке currStr будем хранить текущую строку, которую передает нам плата */
String currStr = "";

/** Переменная принимает значение True, если текущая строка является сообщением */
boolean isStringMessage = false;


void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
  
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
}
 
void loop() {
    digitalWrite(13, false);
    if (monitoringGSM())
        return;

    char key = keypad.getKey();

    if (key != NO_KEY) {
        if (key == '#') {
            lcdPrint("                ", 0);
            lcdPrint("                ", 1);
            strKeypad= "";
        } else if (key == '*') {
            callTo("+" + strKeypad);
        } else {
            strKeypad += key;
        }
    }
    lcdPrint(strKeypad, 1);
}

/**
 * Отрисовывает строку на дисплей
 *
 * @param msg       - строка
 * @param numberStr - номер строки на которой отобразить "msg"
 *                    (0 первая строка, 1 вторая строка)
 */
void lcdPrint(String msg, int numberStr) {
    lcd.setCursor(0, numberStr);
    lcd.print("                ");
    lcd.print(msg);
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
    else {
        char key = keypad.getKey();

        if (key == '*')
            gprsSerial.println("ATA");
        else if (key == '#')
            gprsSerial.println("AT+CHUP");
    }
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