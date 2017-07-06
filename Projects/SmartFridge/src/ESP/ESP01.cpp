#include <Arduino.h>
#include "ESP01.h"
#include <SoftwareSerial.h>


/** заводим Serial-соединение с Esp-01 */
SoftwareSerial espSerial(0, 1);


ESP01::ESP01(uint8_t rxPin, uint8_t txPin)
        : espSerial(SoftwareSerial(rxPin, txPin)) {

    // Esp-01 общается по умолчанию на скорости 115200 бод
    espSerial.begin(115200);

    getCommand("AT+CWMODE=3");
    delay(500);
}


/**
 * Функция опрашивает ESP модуль на наличие сообщений с платы.
 */
bool ESP01::monitoringESP() {
    touch();
    return espSerial.available() != 0;
}

bool ESP01::connectToWiFi(String ssid, String password) {
    return postCommand("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
}

bool ESP01::startServer() {
    if (!postCommand("AT+CIPMODE=0"))
        return false;
    if (!postCommand("AT+CIPMUX=1"))
        return false;
    return postCommand("AT+CIPSERVER=1,8888");

}

bool ESP01::sendMessage(String message) {
    getCommand("AT+CIPSEND=0,16");
    return postCommand(message);
}

bool ESP01::postCommand(String command) {
    espSerial.println(command);
    return "OK" == readSerial();
}

String ESP01::getCommand(String command) {
    espSerial.println(command);
    return readSerial();
}

String ESP01::readSerial() {
    String msg = "";
    while (espSerial.available()) {
        char currSymbol = (char) espSerial.read();
        msg += String(currSymbol);
    }
    return msg;
}


/**
 * Функция провоцирует поддержание коммуникации с модулем даже если
 * он была перезагружен без перезагрузки Arduino
 */
int updateTime = 0;
void ESP01::touch() {
    if (millis() >= updateTime) {
        espSerial.println("AT");
        updateTime += 5000;
    }
}
