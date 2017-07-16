/** Нажатие на кнопку считывается вторым цифровым пином */
#define SW_PIN 2

/** Подключаем к аналоговым пинам оси джостика X и Y */
#define X_PIN A0
#define Y_PIN A1


void setup() {
    pinMode(SW_PIN, INPUT);
    digitalWrite(SW_PIN, HIGH);

    Serial.begin(9600);
}

void loop() {
    Serial.print("Switch:  ");
    Serial.print(digitalRead(SW_PIN));
    Serial.print("\n");
    Serial.print("X-axis: ");
    Serial.print(analogRead(X_PIN));
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.println(analogRead(Y_PIN));
    Serial.print("\n\n");
    delay(500);
}