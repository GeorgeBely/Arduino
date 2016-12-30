#include <DS1302.h>

/** Номера пинов Arduino, к которым подключается модуль реального времени */
#define CLK_PIN 13
#define DAT_PIN 12
#define RST_PIN 10

/** С помощью этой переменной будем получкать данные с модуля */
DS1302 rtc(10, 12, 13);
 
 
void setup() {
    Serial.begin(9600);
}

void loop() {
    Serial.println(getTime());
 
    delay(1000);
}

/**
 * @return текущее время с модуля времени.
 */
String getTime() {
    Time t = rtc.time();

    String result = "";

    result += t.yr;
    result += "-";
    result += t.mon;
    result += "-";
    result += t.date;
    result += "  ";
    result += t.hr;
    result += ":";
    result += t.min;
    result += ":";
    result += t.sec;
    result += "  (";
    result += t.day;
    result += ")";

    return result;
}