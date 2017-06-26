#include <Arduino.h>

#ifndef UNO_GSM_H
#define UNO_GSM_H

class GSM {
    GSM(int rxPin, int txPin);
    bool monitoringGSM(void);
    void answerToCall(String number);
    void callTo(String number);
    void readSMS(String message);
    void sendSMS(String message, String number);
};

#endif //UNO_GSM_H
