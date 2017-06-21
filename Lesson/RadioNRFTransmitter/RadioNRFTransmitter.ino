#include <SPI.h>
#include <RF24.h>

RF24 radio(9, 10);
const uint32_t pipe = 123456789;
byte massiv[64];

void setup() {
    Serial.begin(57600);
    radio.begin();
    radio.setDataRate(RF24_250KBPS);
    radio.setPALevel(RF24_PA_MAX);
    radio.setCRCLength(RF24_CRC_8);
    radio.setRetries(15,15);
    radio.openWritingPipe(pipe);
}

void loop() {
    String text = "ololo pish pish 132&*()1QWERT\\dfoiuytrewqsdfghjk";
    for (int i = 0; i < text.length(); i++) {
        massiv[i] = (byte)text[i];
    }
    radio.write(massiv, sizeof(massiv));
    delay(100);
}