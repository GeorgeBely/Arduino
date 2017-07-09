#include <Arduino.h>
#include "ESP01.h"


ESP01::ESP01(uint8_t rxPin, uint8_t txPin)
        : espSerial(SoftwareSerial(rxPin, txPin)) {
    espSerial.begin(SERIAL_BOLD);

    getCommand(CWMODE);
}

/**
 * Функция опрашивает ESP модуль на наличие сообщений с платы.
 */
bool ESP01::monitoringESP() {
    touch();
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
    return msg;
}

/**
 * Отправляет на esp-01 команду для выполнения {command}.
 *
 * @param command выполняемая команда
 * @return {true}, если команда выполнилась без ошибок, {false} в противном случае
 */
bool ESP01::postCommand(String command) {
    espSerial.println(command);
    return readSerial() == "OK";
}

/**
 * Отправляет на esp-01 запрос для получения информации {query}.
 *
 * @param query выполняемая команда
 * @return результат выполнения команды
 */
String ESP01::getCommand(String query) {
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
