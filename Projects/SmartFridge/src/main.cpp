#include <Arduino.h>
#include <SoftwareSerial.h>

/** заводим Serial-соединение с ESP8266-01 на 7 и 8 цифровых входах */
SoftwareSerial gprsSerial(7, 8);


String msg;




/**
 * Функция провоцирует поддержание коммуникации с платой даже если
 * та была перезагружена без перезагрузки Arduino
 */
int updateTime = 0;
void touch() {
    if (millis() >= updateTime) {
        gprsSerial.println("AT");
        updateTime += 5000;
    }
}




void setup() {
    Serial.begin(9600);
    gprsSerial.begin(115200);

//    gprsSerial.print("AT+CMGF=1\r");
//    delay(300);
//
//    gprsSerial.println("AT+CLIP=1"); // Включаем распознование номера при входящем звонке
    Serial.println("start");
}



void loop() {
    touch();

    msg = "";

    while (gprsSerial.available()) {
        char currSymb = (char) gprsSerial.read();
        if (currSymb != '\n' && currSymb != '\r')
            msg += String(currSymb); // read the incoming data as string
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

        if (msg == "123") {
            gprsSerial.println("AT+CWJAP=\"Rosteldcom_5f69\",\"PFCFTZZR\"");

        } else {

            gprsSerial.println(msg);
        }
    }

    delay(100);
}
