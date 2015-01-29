int ledPin = 13;
boolean value = false;

void setup() {
  pinMode(ledPin, OUTPUT); //подключение пина на выход  
}

void loop() {
  value = !value; //меняем значение светодиода (светиться/не светиться)
  digitalWrite(ledPin, value); //Установка светодиоду в значение value
  delay(2000); //задержка на 2 секунды 
}
