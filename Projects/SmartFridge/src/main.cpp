#include <Arduino.h>
#include "ESP/ESP01.h"


ESP01 esp(7, 8);


void setup() {
    Serial.begin(9600);
    Serial.println("start");
    delay(500);
    esp.espSerial.begin(115200);
    delay(2000);
    esp.espSerial.println("AT+CWMODE=3");
    delay(500);
//    esp.connectToWiFi("Rosteldcom_5f69", "PFCFTZZR");
    delay(500);
//    esp.startServer();
    delay(500);
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

        esp.espSerial.println(msg);
    }

    delay(100);
}
