#include "Arduino.h"
#include "KeypadMobile.h"
#include <Keypad.h>


#define ROWS 4
#define COLS 4

/** Задаём символы соответствующие кнопкам клавиатуры */
char keys[ROWS][COLS] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
        {'*','0','#'}
};
