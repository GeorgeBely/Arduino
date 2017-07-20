#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Wire.h>

const uint64_t pipe = 0xE8E8F0F0E1LL;

RF24 radio(9, 10);


String messageMass[1];

void setup(void) {
    Serial.begin(9600);
    radio.begin();
    radio.openReadingPipe(1, pipe);
    radio.startListening();
    delay(1000);
    radio.openWritingPipe(pipe);
    delay(1000);
}

void loop(void) {
    if (radio.available()) {
        radio.read(messageMass, sizeof(messageMass));
        Serial.println(messageMass[0]);
        delay(100);
    }

    if (Serial.read()) {
        messageMass[0] = "";
        radio.write(temperature, sizeof(temperature));
    }
}