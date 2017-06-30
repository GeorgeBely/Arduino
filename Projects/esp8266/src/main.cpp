#include <Arduino.h>

#import "test/test.h"


void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
}

void loop() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
    Serial.print(MAX_MAX);
    String s = "_333_";
    Serial.println(test(s));
}