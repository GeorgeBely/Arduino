#include <Arduino.h>

#ifndef SMARTFRIDGE_ESP01_H
#define SMARTFRIDGE_ESP01_H


class ESP01 {


public:
    ESP01(uint8_t rxPin, uint8_t txPin);
    bool monitoringESP(void);
    bool connectToWiFi(String ssid, String password);
    bool startServer(void);
    String readSerial();
    bool sendMessage(String message);

private:
    void touch(void);
    bool postCommand(String command);
    String getCommand(String command);

};


#endif
