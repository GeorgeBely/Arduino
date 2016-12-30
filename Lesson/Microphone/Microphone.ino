#define LED_PIN 13

/** Подключаем микрофон к аналоговому выходу 0 */
#define MICROPHONE_PIN A0

/** Зададим пороговую величину звука (Хлопок) */
#define THRESHOLD_VALUE 400


boolean ledValue = false;


void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() { 
    //Считываем данные с микрофона
    int sensorValue = analogRead(MICROPHONE_PIN);

    //Если уровень шума больше порогового значения меняем значение светодиода
    if (sensorValue > THRESHOLD_VALUE)
        ledValue = !ledValue;

    digitalWrite(LED_PIN, ledValue);

    delay(100);
}