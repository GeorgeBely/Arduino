#include <Arduino.h>
#include <SoftwareSerial.h>

/** заводим Serial-соединение с ESP8266-01 на 7 и 8 цифровых входах */
SoftwareSerial gprsSerial(7, 8);


String msg;




/**
 * Функция провоцирует поддержание коммуникации с платой даже если
 * та была перезагружена без перезагрузки Arduino
 */
int updateTime2 = 0;
void touch2() {
    if (millis() >= updateTime2) {
        gprsSerial.println("AT");
        updateTime2 += 5000;
    }
}




void setup() {
    Serial.begin(9600);
    gprsSerial.begin(9600);

    Serial.println("start");
}


void loop() {
    touch2();

    msg = "";
    while (gprsSerial.available()) {
        msg += gprsSerial.readString();
    }

    if (msg != "") {
        Serial.println(msg);
    }


    msg = "";
    while (Serial.available()) {
        msg += Serial.readString(); // read the incoming data as string
    }
    if (msg != "") {
        Serial.print("Send to esp |");
        Serial.print(msg);
        Serial.println("|");
        gprsSerial.println(msg);
    }

    delay(100);
}

