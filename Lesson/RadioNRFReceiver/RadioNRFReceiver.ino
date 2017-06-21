#include <SPI.h>
#include <RF24.h>

const uint32_t pipe = 123456789;

String msg;

RF24 radio(9, 10);

byte massiv[64];

void setup() {
    Serial.begin(57600);
    radio.begin();
    radio.setDataRate(RF24_250KBPS);
    radio.setPALevel(RF24_PA_MAX);
    radio.setCRCLength(RF24_CRC_8);
    radio.setRetries(15,15);
    radio.openWritingPipe(pipe);
    radio.openReadingPipe(1,pipe);
    radio.startListening();
}


void loop() {
    if(radio.available()) {
        radio.read(massiv, sizeof(massiv));
        String myString = String((char *)massiv);
        Serial.println(myString);

        delay(100);
    }
}
