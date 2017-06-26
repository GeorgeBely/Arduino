#include <Arduino.h>
#include "gsm.h"
#include <SoftwareSerial.h>


class GSM {

    /** заводим Serial-соединение с GPRS-Shield на 7 и 8 цифровых входах */
    SoftwareSerial gprsSerial;


    GSM(int rxPin, int txPin) {
        gprsSerial = SoftwareSerial(rxPin, txPin);

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


    /**
     * Функция опрашивает GSM модуль на наличие входящего звонка или СМС.
     * При их наличии реагирует должным образом.
     * Для ответа используется функция answerToCall()
     * Для прочтения СМС используется функция readSMS()
     */
    bool monitoringGSM() {
        touch();

        if (!gprsSerial.available())
            return false;

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
                return true;
            } else if (currStr.startsWith("+CLIP")) {
                // Получен символ перевода строки, это значит, что текущее
                // сообщение от платы завершено и мы можем на него отреагировать.
                // Если текущая строка - это RING, то значит, нам кто-то звонит
                answerToCall(currStr.substring(8, 20));
                Serial.println(currStr);
            }
            currStr = "";
        } else if (currSymbol != '\n') {
            // Дополняем текущую команду новым сиволом
            // При этом игнорируем второй символ в последовательности переноса
            // строки: \r\n
            currStr += String(currSymbol);
        }

        return true;
    }

    /**
     * Ответ на входящий звонок
     */
    void answerToCall(String number) {
        lcdPrint("incoming call", 0, 0);
        lcdPrint(number, 1, 0);

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
        lcdPrint("call to", 0, 0);
        lcdPrint(number, 1, 0);

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
        lcdPrint("Incoming message", 0, 0);
        lcdPrint(message, 1, 0);
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
        gprsSerial.println((char) 26);
    }


    /**
     * Функция провоцирует поддержание коммуникации с платой даже если
     * та была перезагружена без перезагрузки Arduino
     */
    int updateTime = 0;

    private:void touch() {
        if (millis() >= updateTime) {
            gprsSerial.println("AT");
            updateTime += 5000;
        }
    }
};