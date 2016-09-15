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


//Функция сглаживает помехи от дальномера и возвращает расстояние.
//Первый аргумент - пин к которому подключён выход дальномера trig,
//Второй аргумент - пин к которому подключён выход дальномера echo.
int getMaxRange(int trig, int echo) {
  int range;

  //Получаем расстояние.
  int range1 = getRange(trig, echo);
  range = range1;
  delay(100);

  int range2 = getRange(trig, echo);
  if (range2 > range)
    range = range2;
  delay(100);

  int range3 = getRange(trig, echo);
  if (range3 > range)
    range = range3;
  delay(100);

  int range4 = getRange(trig, echo);
  if (range4 > range)
    range = range4;

  return range;
}

//Отображает переданное число на дисплее
//Первый аргумант - число, которое нужно отобразить
//Второй аргумент - если передано true, будет отображено
//                  двоеточие между цифрами
void setDisplayValue(int value, boolean usePoint) {
  //Значения для отображения на каждом из 4 разрядов
  int8_t disp[4];
  disp[0] = disp[1] = disp[2] = disp[3] = 0;

  int res = value;
  int i = 3;
  while (res > 0 && i >= 0) {
    disp[i] = res % 10;
    res = res / 10;
    i--;
  }

  display.display(disp);

  //будем включать и выключать двоеточие каждую секунду
  display.point(usePoint);
}

//Определяет наличие движения с помощью датчика движения
//Первый аргумент - намер пина, к которому подключён датчик движения
//prevState - переменная, которая хранит предыдущее значение наличия движения.
int prevState = LOW;
boolean isMoveEnable(int moveSensorPin) {
  boolean val = digitalRead(moveSensorPin);
  if (val != prevState) {
    prevState = val;
    return true;
  }
  return false;
}

