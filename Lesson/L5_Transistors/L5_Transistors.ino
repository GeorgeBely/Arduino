int tranPin = 7;

//Текушее значение транзистора
boolean value = false;

void setup() {
  pinMode(tranPin, OUTPUT);
}

void loop() {
  //Меняем значение транзистора
  value = !value;     
  //При "value == true" на транзистор будет подан ток и 
  //он будет пропускать основной ток.
  digitalWrite(tranPin, value);
  //Задержка 2 секунды
  delay(2000);
}