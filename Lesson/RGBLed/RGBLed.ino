/** Подключаем потенциометры */
#define POT_RED_PIN A0
#define POT_GREEN_PIN A1
#define POT_BLUE_PIN A2

/** Подключаем RGB светодиод */
#define LED_RED_PIN 11
#define LED_GREEN_PIN 10
#define LED_BLUE_PIN 9


void setup() {
    pinMode(LED_RED_PIN, INPUT);
    pinMode(LED_GREEN_PIN, INPUT);
    pinMode(LED_BLUE_PIN, INPUT);
}

void loop() {
    analogWrite(LED_RED_PIN, 255 - analogRead(POT_RED_PIN) / 4);
    analogWrite(LED_GREEN_PIN, 255 - analogRead(POT_GREEN_PIN) / 4);
    analogWrite(LED_BLUE_PIN, 255 - analogRead(POT_BLUE_PIN) / 4);
}
