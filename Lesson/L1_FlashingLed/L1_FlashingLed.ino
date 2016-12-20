int ledPin = 13;

//Метод, который запускается при включение arduino
void setup() {
  pinMode(ledPin, OUTPUT); //подключение пина на выход  
}

//Метод, который бесконечно повторяется на протяжение всей работы arduino
void loop() {
  digitalWrite(ledPin, true); //Включаем светодиод
  delay(2000); //задержка на 2 секунды
  digitalWrite(ledPin, false); //Выключаем светодиод
  delay(2000); //задержка на 2 секунды
}
