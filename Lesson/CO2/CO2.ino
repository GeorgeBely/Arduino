/**
 * Библиотека для работы с датчиком CO2.
 * Перед использованием необходимо установить в библиотеки значение RLOAD в соответствии с используемом на датчике резистором.
 * Значение RZERO необходимо рассчитать для хорошо проветриваемого помещения.
 */
#include <MQ135.h>
#include "DHT.h"

/** Подключаем датчик CO2 к аналоговому пину 0 */
#define CO2_PIN A0
/** А так же к цифровому пину 7 (Не обязательно) */
#define CO2_DIGITAL_PIN 7

/** Подключаем термометр к пину 2 */
#define DHT_PIN 2

/** Подключаем светодиод к 13 пину */
#define LED_PIN 13

/** Для датчика AM2301 задаём: DHT21 */
#define DHTTYPE DHT21


/** Переменная для работы с датчиком СО2 */
MQ135 mq(CO2_PIN);

/**
 * Датчик CO2 будем корректировать в зависимости от температуры и влажности.
 * С помощью этой переменной будем получать и обрабатывать данные с термометра.
 */
DHT dht(DHT_PIN, DHTTYPE);


void setup() {
    Serial.begin(9600);
    dht.begin();
    pinMode(CO2_DIGITAL_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);

    //Перед использованием датчик нужно прогреть. Прогревать от 1 до 5 минут
    Serial.print("Calibrating ");
    for(int i = 0; i < 60; i++) {
        Serial.print(".");
        delay(1000);
    }
    Serial.println("");
}

void loop() {
    float h = dht.readHumidity(); // Считываем влажность воздуха в процентах
    float t = dht.readTemperature(); // Считываем температуру в градусах
    double CO2 = mq.getCorrectedPPM(t, h); // Считываем уровень СО2 в PPM
    bool thresholdExceeded = digitalRead(CO2_DIGITAL_PIN); // {true}, если больше заданного потенциометром порога

    digitalWrite(LED_PIN, !thresholdExceeded);

    Serial.print("CO2: ");
    Serial.print(CO2);
    Serial.println("ppm");
  
    delay(1000);
}
