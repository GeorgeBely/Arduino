int ledPin = 13;
int buttonPin = 8;

boolean ledValue = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT); //Устанавливаем пин на считывание
}

void loop() {
  //Если кнопка нажата меняем значение светодиода
  if (changeButton(buttonPin))
    ledValue = !ledValue;

  digitalWrite(led, ledValue);
}

//Предыдушее значение нажатия кнопки
boolean lastButton = false;
//Функция для определения нажатия кнопки
boolean changeButton(int button) {
  //Получаем текушее значение нажатия кнопки
  boolean current = digitalRead(button);
  if (current != lastButton) {
    delay(5);
    //Убираем помехт. За 5 милисекунд человек не успеет убрать палец.
    current = digitalRead(button);

    //Проверяем, что до этого кнопка была не нажата, а сейчас нажата
    if (lastButton ==  LOW && current == HIGH) {
      //Если верно, то запоминаем, что копка нажата,
      lastButton = current;
      return true;
    }
  }
  lastButton = current;
  return false;
}

