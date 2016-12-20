#include <DS1302.h>
 
int CLK = 13;
int DAT = 12;
int RST = 10;
 
DS1302 rtc(10, 12, 13);
 
 
void setup()
{
    Serial.begin(9600);
}
 
 
void loop()
{
    Time t = rtc.time();
    Serial.print(t.yr);
    Serial.print("-");
    Serial.print(t.mon);
    Serial.print("-");
    Serial.print(t.date);
    Serial.print("  ");
    Serial.print(t.hr);
    Serial.print(":");
    Serial.print(t.min);
    Serial.print(":");
    Serial.print(t.sec);
    Serial.print("  (");
    Serial.print(t.day);
    Serial.println(")");
 
    delay(1000);
}
