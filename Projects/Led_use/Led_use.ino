#include <Wire.h>
#include <EEPROM.h>
#include "TM1637.h"


#define MAX_SEK_USE_LED_COUNT 30

//Номера пинов Arduino, к которым подключается индикатор
#define DISPLAY_CLK_PIN 12  
#define DISPLAY_DIO_PIN 13

//Номер пина Arduino, к которому подключено реле
#define RELAY_PIN 2

//Номер пина к которому подключён датчик движения
#define MOVE_SENSOR_PIN 3

//Номер аналогового пина, к которому подклчёт фоторезистор
#define PHOTORESISTOR_PIN A5

//Для работы с микросхемой часов и индикатором мы используем библиотеки
//Классы TM1637 и DS1307 объявлены именно в них
TM1637 display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);
 
 
double useLedTime = 0;
int count = 0;

void setup() {
  //Включаем и настраиваем индикатор
  display.set();
  display.init();
    
  //Запускаем arduino на порте 9600, для общения с компьютером
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  pinMode(MOVE_SENSOR_PIN, INPUT);
}

void loop() {
  boolean haveMove = isMoveEnable(MOVE_SENSOR_PIN);
  
  if (haveMove) {
    digitalWrite(RELAY_PIN, false);
    useLedTime = MAX_SEK_USE_LED_COUNT;
  } else {  
    if (useLedTime <= 0) {
      int lightVal = analogRead(PHOTORESISTOR_PIN);
    
      setDisplayValue(lightVal, true);
      digitalWrite(RELAY_PIN, true);
    } else if (useLedTime <= 0.1) {
      count++;
      useLedTime -= 0.1;
    } else {
      useLedTime -= 0.1;
      setDisplayValue(useLedTime * 10, false);
    }
  }
  
  delay(100);
}


//Определяет наличие движения с помощью датчика движения
//Первый аргумент - намер пина, к которому подключён датчик движения
//prevState - переменная, которая хранит предыдущее значение наличия движения.
int prevState = LOW;
boolean isMoveEnable(int moveSensorPin) {
  boolean val = digitalRead(moveSensorPin);
  if (val != prevState) {
    prevState = val;
    return true;
  }
  return false;
}


//Отображает переданное число на дисплее
//Первый аргумант - число, которое нужно отобразить
//Второй аргумент - если передано true, будет отображено 
//                  двоеточие между цифрами
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
