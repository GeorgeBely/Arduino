#include <Arduino.h>

#ifndef UNO_GSM_H
#define UNO_GSM_H

class GSMMobile {

public:
    GSMMobile(uint8_t rxPin, uint8_t txPin);
    bool monitoringGSM(void);
    void answerToCall(String number);
    void callTo(String number);
    void readSMS(String message);
    void sendSMS(String message, String number);

private:
    void touch(void);

};


#endif