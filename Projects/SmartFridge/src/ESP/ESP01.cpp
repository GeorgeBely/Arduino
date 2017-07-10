#include <Arduino.h>
#include "ESP01.h"


ESP01::ESP01(uint8_t rxPin, uint8_t txPin)
        : espSerial(SoftwareSerial(rxPin, txPin)) {
    espSerial.begin(SERIAL_BOLD);
}

/**
 * Функция опрашивает ESP модуль на наличие сообщений с платы.
 */
bool ESP01::monitoringESP() {
//    touch();
    return espSerial.available() != 0;
}

/**
 * Отправляет сообщение указанному клиенту
 *
 * @param clientId id клиента, которому нужно отправить сообщение
 * @param message сообщение
 * @return {true}, если сообщение было отправлено
 */
bool ESP01::sendMessage(int clientId, String message) {
    String cipsend = "AT+CIPSEND=";
    cipsend += clientId;
    cipsend += ",16";
    postCommand(cipsend);
    return postCommand(message);
}

/**
 * Запускает локальный сервер на порту {LOCAL_SERVER_PORT}
 *
 * @return {true}, если сервер стартанул, {false} в противном случае
 */
bool ESP01::startServer() {
    if (!postCommand(CIPMODE))
        return false;
    if (!postCommand(CIPMUX))
        return false;
    return postCommand(CIPSERVER);
}

/**
 * Подключается к указанной Wi-Fi точке
 *
 * @param ssid     id wi-fi точки
 * @param password пароль
 * @return {true}, если подключение прошло успешно, {false} в противном случае
 */
bool ESP01::connectToWiFi(String ssid, String password) {
    if (!postCommand(CWMODE))
        return false;
    return postCommand("AT+CWJAP=\"" + ssid + "\",\"" + password + "\"");
}

/**
 * Считывает сообщение с платы
 *
 * @return прочитанное сообщение при его наличии, или пустую строку при его отсутствии
 */
String ESP01::readSerial() {
    String msg = "";
    while (espSerial.available()) {
        msg += espSerial.readString();
    }
    return cutResultCommand(msg);
}

/**
 * Отправляет на esp-01 команду для выполнения {command}.
 *
 * @param command выполняемая команда
 * @return {true}, если команда выполнилась без ошибок, {false} в противном случае
 */
bool ESP01::postCommand(String command) {
    delay(5000);
    Serial.println("------send command--------" + command);
    espSerial.println(command);
    String read = readSerial();
    Serial.println("++++++read result+++++++++" + read);
    Serial.println();

    Serial.println(read.equals("OK"));
    return read.equals("OK");
}

/**
 * Отправляет на esp-01 запрос для получения информации {query}.
 *
 * @param query выполняемая команда
 * @return результат выполнения команды
 */
String ESP01::getCommand(String query) {
    delay(1000);
    espSerial.println(query);
    return readSerial();
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


String ESP01::cutResultCommand(String result) {
    while (result.charAt(result.length() - 1) == '\n') {
        result = result.substring(0, result.length() - 1);
    }
    if (result.indexOf("\n") != -1) {
        result = result.substring((unsigned int) (result.lastIndexOf('\n') + 1), result.length());
    }

    return "|" + result + "|";
}