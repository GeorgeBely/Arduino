/** Подключаем библиотеку DHT для считывания температуры и влажности воздуха с датчика AM*** */
#include "DHT.h"

/** Подключаем термометр к пину 2 */
#define DHT_PIN 2

/** Lkz Датчика AM2301 задаём: DHT21 */
#define DHTTYPE DHT21

/** С помощью этой переменной будем получать и обрабатывать данные с термометра */
DHT dht(DHTPIN, DHTTYPE);


void setup() {
    Serial.begin(9600);

    dht.begin();
}

void loop() {
    float h = dht.readHumidity(); // Считываем влажность воздуха в процентах
    float t = dht.readTemperature(); // Считываем температуру в градусах

    // проверяем, что данные корректны
    if (isnan(t) || isnan(h)) {
        Serial.println("Failed to read from DHT");
    } else {
        Serial.print("Humidity: ");
        Serial.print(h);
        Serial.print(" %\t");
        Serial.print("Temperature: ");
        Serial.print(t);
        Serial.println(" *C");
    }

    delay(2000);
}