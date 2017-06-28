#include "Arduino.h"

#ifndef UNO_LCDMOBILE_H
#define UNO_LCDMOBILE_H


class LCDMobile {

public:
    LCDMobile(uint8_t rxPin, uint8_t txPin);
    void lcdPrint(String msg, uint8_t numberStr, uint8_t startSymbol);
    void cursor(void);
    void noCursor(void);

};


#endif
