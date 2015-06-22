#include "TM1637.h"

const int analogInPin = A0; 

#define DISPLAY_CLK_PIN 11  
#define DISPLAY_DIO_PIN 12

TM1637 display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);

int sensorValue = 0; 

void setup() { 
  display.set();
  display.init();
} 

void loop() { 
  sensorValue = analogRead(analogInPin);
  setDisplayValue(sensorValue, false);  
  delay(100);                     
}


void setDisplayValue(int value, boolean usePoint) {
  //Значения для отображения на каждом из 4 разрядов
  int8_t disp[4];
  disp[0] = disp[1] = disp[2] = disp[3] = 0;
  
  int res = value;
  int i = 3;
  while (res > 0 && i >= 0) {
    disp[i] = res % 10;
    res = res / 10;
    i--;    
  }

  display.display(disp);
 
  //будем включать и выключать двоеточие каждую секунду
  display.point(usePoint);
}