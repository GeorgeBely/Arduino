#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
// Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity

float temperature[2];

RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void) {
    Serial.begin(9600);
    radio.begin();
    radio.openReadingPipe(1, pipe);
    radio.startListening();
    delay(1000);
}

void loop(void) {
    if ( radio.available() ) {
        radio.read(temperature, sizeof(temperature));
        Serial.print(temperature[0]);
        Serial.print("     ");
        Serial.println(temperature[1]);
        delay(100);
    }
}
