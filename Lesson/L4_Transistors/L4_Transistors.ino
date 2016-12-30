/**
 * Подключаем ногу (база) транзистора к 7 пину
 */
#define TRAN_PIN 7

/**
 * Текушее значение транзистора
 */
boolean value = false;


void setup() {
    pinMode(TRAN_PIN, OUTPUT);
}

void loop() {
    //Меняем значение транзистора
    value = !value;

    //При "value == true" на транзистор будет подан ток и
    //он будет пропускать основной ток.
    digitalWrite(TRAN_PIN, value);

    //Задержка 2 секунды
    delay(2000);
}