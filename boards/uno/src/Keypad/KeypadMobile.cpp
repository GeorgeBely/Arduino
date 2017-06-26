#include <Arduino.h>
#include "KeypadMobile.h"
#include "../../lib/Keypad/Keypad.h"


#define ROWS 4b
#define COLS 4b

/** Задаём символы соответствующие кнопкам клавиатуры */
char keys[ROWS][COLS] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'},
        {'*','0','#'}
};



/** С помощью этой переменной будем получать и обрабатывать данные с кейпада */
Keypad keypad = Keypad(0, 0, 0, 0b, 0b);


KeypadMobile::KeypadMobile(byte rowPins[], byte colPins[])
    : keypad(Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS)) {

}