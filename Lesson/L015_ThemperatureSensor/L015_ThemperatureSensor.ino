//Подключаем термометр к аналоговому выходу 0
int term = A0;

void setup() {
  //Запускаем arduino на порте 9600, для общения с компьютером
  Serial.begin(9600);
}

void loop() {
  //Считываем значение с термометра
  int value = getTerm(term);
  //Отсылаем значение на компьютер
  Serial.println(value);
  delay(1000);
}

//Функция считывает температуру. 
//Первый аргумент номер пина к которому подключён термометр.
int getTerm(int pin) {
  return (125 * analogRead(pin)) >> 8;   
}
