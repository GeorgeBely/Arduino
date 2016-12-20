#include <Wire.h>
#include <EEPROM.h>
#include "TM1637.h"
 
  
 
//Номера пинов Arduino, к которым подключается индикатор
#define DISPLAY_CLK_PIN 11  
#define DISPLAY_DIO_PIN 12
 
boolean point = false; 
 
//Для работы с микросхемой часов и индикатором мы используем библиотеки
//Классы TM1637 и DS1307 объявлены именно в них
TM1637 display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
  
void setup() {
  //Включаем и настраиваем индикатор
  display.set();
  display.init();
}
 
 
void loop() {
  for (int i = 0; i < 2000; i++) {
    setDisplayValue(i, point); 
    if (i % 10 == 0)
      point = !point;
    delay(100);
  }
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
