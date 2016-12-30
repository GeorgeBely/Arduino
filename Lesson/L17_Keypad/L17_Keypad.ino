#include "Keypad.h"

#define ROWS 4
#define COLS 4

/** Задаём символы соответствующие кнопкам клавиатуры */
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

/**
 * Задаём соответствыя, к каким пинам подключена строка. Можно использовать как аналоговые пины, так и цифровые.
 */
byte rowPins[ROWS] = {A1, A2, A3, A4};

/**
 * Задаём соответствыя, к каким пинам подключена строка. Можно использовать как аналоговые пины, так и цифровые.
 */
byte colPins[COLS] = {3, 4, 5};

/** С помощью этой переменной будем получать и обрабатывать данные с кейпада */
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup() {
    Serial.begin(9600);
}

void loop() {
    char key = keypad.getKey();

    //Проверяем, что кнопка нажата
    if (key != NO_KEY){
        Serial.println(key);
    }
}
