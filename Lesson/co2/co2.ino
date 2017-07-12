#include <MQ135.h>

/** Подключаем датчик CO2 к аналоговому пину 0 */
#define CO2_PIN A0


MQ135 mq(CO2_PIN);


void setup(){
    Serial.begin(9600);
  
    Serial.print("Calibrating ");
    for(int i = 0; i < 40; i++){
        Serial.print(".");
        delay(1000);
    }
    Serial.println("");
}

void loop(){
    double CO2 = mq.getPPM();
  
    Serial.print("CO2: ");
    Serial.print(CO2);
    Serial.println("ppm");
  
    delay (1000);
}