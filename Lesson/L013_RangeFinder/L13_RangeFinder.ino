int echoPin = 7;
int trigPin = 8;

void setup() {
  //Запускаем arduino на порте 9600, для общения с компьютером
  Serial.begin(9600);
  //Пин trig установливаем в подачу тока.
  pinMode(trigPin, OUTPUT);
  //Пин echo установливаем на считывание тока.
  pinMode(echoPin, INPUT);  
}

void loop() {
  //Получаем расстояние.
  int range = getRange(trigPin, echoPin);
  //Отправляем на компьютер расстояние. Функция print в 
  //отличие от функции println не добавляет в конец строки 
  //переход на новую строку. 
  Serial.print("Расстояние: ");
  //Так мы можем собрать необходимую нам строку.
  Serial.print(range);
  //И отправить её с помощью функции println на компьютер.
  //Тоесть при расстояние 230 см 
  //на компьютер будет отослана строка в виде:
  //Расстояние 230 см
  Serial.println(" см");
  //Делаем задержку на 100 или более для того,
  //чтобы нам точно не мешал предыдущий сигнал.
  delay(100);
}

//Функция возвращает расстояние от дальномера. 
//Первый аргумент - пин к которому подключён выход дальномера trig, 
//Второй аргумент - пин к которому подключён выход дальномера echo.
int getRange(int trig, int echo) {
  digitalWrite(trig, HIGH);
  delayMicroseconds(2000);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);
  int distance = (duration/2) / 29.1; 
  
  return distance;
}
