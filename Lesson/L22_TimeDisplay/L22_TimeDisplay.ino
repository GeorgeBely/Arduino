#include <Wire.h>
#include <EEPROM.h>
#include "TM1637.h"
 
/** Номера пинов Arduino, к которым подключается индикатор */
#define DISPLAY_CLK_PIN 11  
#define DISPLAY_DIO_PIN 12

 
boolean point = false;

/** С помощью этой переменной будем отрисовывать данные на дисплей */
TM1637 display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);


void setup() {
    //Включаем и настраиваем индикатор
    display.set();
    display.init();
}

void loop() {
    for (int i = 0; i < 2000; i++) {
        setDisplayValue(i, point);

        //будем включать и выключать двоеточие каждую секунду
        if (i % 10 == 0)
            point = !point;

        delay(100);
    }
}

/**
 * Функция отображает переданное число на светодиодном индикаторе
 *
 * @param value    - число, которое нужно отобразить (4 значное или меньше)
 * @param usePoint - если {true}, то отображать двоеточие между числами
 */
void setDisplayValue(int value, boolean usePoint) {
    //Значения для отображения на каждом из 4 разрядов
    int8_t disp[4];
    disp[0] = disp[1] = disp[2] = disp[3] = 0;

    int res = value;
    int i = 3;
    while (res > 0 && i >= 0) {
        disp[i] = res % 10;
        res = res / 10;
        i--;
    }

    display.display(disp);
    display.point(usePoint);
}