#include <Arduino.h>
#include "ESP/ESP01.h"


ESP01 esp(7, 8);


void setup() {
    Serial.begin(9600);
    Serial.println("start");

    esp.connectToWiFi("Rosteldcom_5f69", "PFCFTZZR");
    esp.startServer();
}



void loop() {
    if (esp.monitoringESP()) {
        String message = esp.readSerial();
        Serial.println(message);
    }

    if (Serial.available()) {
        String msg = Serial.readString();
        Serial.print("Send to esp |");
        Serial.print(msg);
        Serial.println("|");

        esp.sendMessage(msg);
    }

    delay(100);
}
