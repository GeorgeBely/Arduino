#include <Wire.h>
#include <EEPROM.h>
#include "TM1637.h"


/** Устанавливаем максимальное колличество секунд, при которых свет будет гореть без наличия движения */
#define MAX_SEK_USE_LED_COUNT 30

/** Номера пинов Arduino, к которым подключается светодиодный индикатор */
#define DISPLAY_CLK_PIN 12  
#define DISPLAY_DIO_PIN 13

/** Номер пина Arduino, к которому подключено реле */
#define RELAY_PIN 2

/** Номер пина к которому подключён датчик движения */
#define MOVE_SENSOR_PIN 3

/**
 * Для работы с микросхемой часов и индикатором мы используем библиотеки
 * Классы TM1637 и DS1307 объявлены именно в них
 */
TM1637 display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
 
/** Переменная хранит время оставшиеся до отключения света */
double useLedTime = 0;


void setup() {
    display.set();
    display.init();
    
    Serial.begin(9600);

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(MOVE_SENSOR_PIN, INPUT);
}

void loop() {
    boolean haveMove = isMoveEnable(MOVE_SENSOR_PIN);
  
    if (haveMove) {
        digitalWrite(RELAY_PIN, false);
        useLedTime = MAX_SEK_USE_LED_COUNT;
    } else {
        if (useLedTime <= 0) {
            digitalWrite(RELAY_PIN, true);
        } else {
            useLedTime -= 0.1;
            setDisplayValue(useLedTime * 10, false);
        }
    }
  
    delay(100);
}

/**
 * Функция определяет наличие движения с помощью датчика движения
 *
 * @param moveSensorPin - намер пина, к которому подключён датчик движения
 * prevState - переменная, которая хранит предыдущее значение наличия движения.
 *
 * @return {true}, если датчик зафиксировал движение
 */
int prevState = LOW;
boolean isMoveEnable(int moveSensorPin) {
    boolean val = digitalRead(moveSensorPin);
    if (val != prevState) {
        prevState = val;
        return true;
    }
    return false;
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
