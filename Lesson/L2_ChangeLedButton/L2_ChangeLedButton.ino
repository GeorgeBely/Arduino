#define LED_PIN 13
#define BUTTON_PIN 8


void setup() {
    pinMode(LED_PIN, OUTPUT); //Устанавливаем значение пина на выход (подача тока)
    pinMode(BUTTON_PIN, INPUT); //Устанавливаем значение пина на вход
}


void loop() {
    //Считываем значение с пина который подключён к кнопке.
    //Если есть ток то вернёт true.
    boolean value = digitalRead(BUTTON_PIN);
    digitalWrite(LED_PIN, value);
}