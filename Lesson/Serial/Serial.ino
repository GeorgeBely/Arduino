/**
 * Создаём Serial подключение на порту 9600
 */
void setup() {
    Serial.begin(9600);
}

void loop() {
    // Метод Serial.println отправляет переданную строку
    Serial.println("Hello");

    // Метод Serial.print не отправляет строку, но записывает её в буфер
    // и когда будет вызван метод Serial.println он сконтектенирует
    // переданную строку со строкой в буфере и отправит её
    Serial.print(" wo");
    Serial.print("rld");
    Serial.println("!");
}