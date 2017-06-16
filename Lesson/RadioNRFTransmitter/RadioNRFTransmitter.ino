#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int pin = A0;
float temperature[2];

double Fahrenheit(double celsius) {
    return ((double)(9 / 5) * celsius) + 32;
}

double Kelvin(double celsius) {
    return celsius + 273.15;
}

RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void) {
    radio.begin();
    radio.openWritingPipe(pipe);
}

int count = 0;

void loop(void) {
    count++;
    float temp, humi;
    temperature[0] = count;
    temperature[1] = 123;
    radio.write(temperature, sizeof(temperature));
    delay(100);
}