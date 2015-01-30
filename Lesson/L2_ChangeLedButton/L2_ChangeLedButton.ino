int ledPin = 13;
int buttonPin = 8;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); //Устанавливаем пин на считывание
}

void loop() {
  //Считываем значение с пина который подключён к кнопке.
  //Если есть ток то вернёт true.
  boolean value = digitalRead(buttonPin);
  digitalWrite(led, value); 
}