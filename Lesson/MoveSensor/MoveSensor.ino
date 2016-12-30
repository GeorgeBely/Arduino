#include <Arduino.h>

/** Номер пина Arduino, к которому подключено реле */
#define LED_PIN 13

/** Номер пина к которому подключён датчик движения */
#define MOVE_SENSOR_PIN 3


void setup() {
    Serial.begin(9600);
    pinMode(LED_PIN, OUTPUT);
    pinMode(MOVE_SENSOR_PIN, INPUT);
}

void loop() {
    boolean haveMove = isMoveEnable(MOVE_SENSOR_PIN);
    if (haveMove) {
        digitalWrite(LED, HIGH);
        Serial.println("Зафиксировано движение!");
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