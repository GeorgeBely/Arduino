/**
 * Управлять реле будем с помощью пина 7
 */
#define RELAY_PIN 7

/**
 * Текушее значение положения реле
 */
boolean value = false;


void setup() {
    pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
    //Меняем положение реле
    value = !value;
    digitalWrite(RELAY_PIN, value);

    //Задержка 2 секунды
    delay(2000);
}