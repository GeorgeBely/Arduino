#include <Arduino.h>
#include "ESP/ESP01.h"


ESP01 esp(7, 8);


void setup() {
    Serial.begin(9600);
    Serial.println("start");
    delay(5000);
    if (esp.connectToWiFi("Rostelecom_5f69", "PFCFTZZR")) {
        Serial.println("Connect to Wi-Fi");
    } else {
        Serial.println("Not connect to Wi-fi");
    }
    delay(5000);
    if (esp.startServer()) {
        Serial.println("Start server");
    } else {
        Serial.println("Server not started");
    }
    delay(5000);
}


void loop() {
//    if (esp.monitoringESP()) {
//        String message = esp.readSerial();
//        Serial.println(message);
//    }

    if (Serial.available()) {
        String msg = Serial.readString();
        Serial.print("Send to esp |");
        Serial.print(msg);
        Serial.println("|");

        esp.espSerial.println(msg);
//        esp.sendMessage(0, msg);
    }

    delay(100);
}
