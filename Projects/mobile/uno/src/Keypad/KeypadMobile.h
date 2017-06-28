#include "Arduino.h"

#ifndef UNO_KEYPADMOBILE_H
#define UNO_KEYPADMOBILE_H


class KeypadMobile {


public:
    const char NO_KEY;
    KeypadMobile(byte rowPins[], byte colPins[]);
    char getKey();
};


#endif