/** Подключаем дальномер */
#define ECHO_PIN 7
#define TRIG_PIN 8

#define LED_PIN 13


void setup() {
    Serial.begin(9600);

    pinMode(LED_PIN, OUTPUT); //Пин trig установливаем в подачу тока.
    pinMode(TRIG_PIN, OUTPUT); //Пин trig установливаем в подачу тока.
    pinMode(ECHO_PIN, INPUT); //Пин echo установливаем на считывание тока.
}

void loop() {
    int distance = getRange(trigPin, echoPin);
    Serial.print(distance);
    Serial.println("cm");

    if (distance < 100 && distance > 20) {
        digitalWrite(ledPin, true);
        delay(60000);
        digitalWrite(ledPin, false);
    }

  delay(100);
}

/**
 * Функция возвращает расстояние от дальномера.
 *
 * @param trig - пин к которому подключён выход дальномера trig,
 * @param echo - пин к которому подключён выход дальномера echo.
 *
 * @return расстояние до ближайшего объекта от дальномера
 */
int getRange(int trig, int echo) {
    digitalWrite(trig, HIGH);
    delayMicroseconds(2000);
    digitalWrite(trig, LOW);
    int duration = pulseIn(echo, HIGH);
    int distance = (duration/2) / 29.1;

    return distance;
}
