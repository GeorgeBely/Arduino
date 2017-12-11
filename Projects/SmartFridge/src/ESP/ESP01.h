#include <Arduino.h>
#include <SoftwareSerial.h>

#ifndef SMARTFRIDGE_ESP01_H
#define SMARTFRIDGE_ESP01_H


class ESP01 {


    /** Номер порта на котором стартует локальные сервер */
    const int LOCAL_SERVER_PORT = 8080;

    /**
     * Устанавливаем режим работы c Wi-Fi
     * 1 — STA  (Подключение к Wi-Fi точке)
     * 2 — AP   (Создание собственной Wi-Fi точки, запуск локального сервера)
     * 3 — BOTH (Совмщённый режим. Возможно подключиться к Wi-Fi и запустить сервер)
     */
    const String CWMODE = "AT+CWMODE=3";

    /**
     * Устанавливаем режим передачи данных.
     * mode = 0 — not data mode (сервер может отправлять данные клиенту и может принимать данные от клиента)
     * mode = 1 — data mode (сервер не может отправлять данные клиенту, но может принимать данные от клиента)
     */
    const String CIPMODE = "AT+CIPMODE=0";

    /**
     *  Устанавливаем возможность множественных соединений:
     *  0 — Одно соединение
     *  1 — Множественное соединение
     */
    const String CIPMUX = "AT+CIPMUX=1";

    /**
     * Запуск сервера: AT+CIPSERVER=<mode>,<port>
     * mode 0 — закрытый сервер
     * mode 1 — открытый сервер
     * port - порт на котором стартует сервер
     */
    const String CIPSERVER = "AT+CIPSERVER=1," + LOCAL_SERVER_PORT;



public:
    /** Скорость последовательного подключения */
    static const int SERIAL_BOLD = 19200;

    SoftwareSerial espSerial;
    ESP01(uint8_t rxPin, uint8_t txPin);
    bool monitoringESP(void);
    bool connectToWiFi(String ssid, String password);
    bool startServer(void);
    String readSerial();
    bool sendMessage(int clientId, String message);

private:
    bool postCommand(String command);
    String getCommand(String query);
    void touch(void);
    String cutResultCommand(String result);

};


#endif
