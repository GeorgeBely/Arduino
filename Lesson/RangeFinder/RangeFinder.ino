/** Подключаем дальномер */
#define ECHO_PIN 7
#define TRIG_PIN 8


void setup() {
    Serial.begin(9600); //Запускаем arduino на порте 9600, для общения с компьютером

    pinMode(TRIG_PIN, OUTPUT); //Пин trig установливаем в подачу тока.
    pinMode(ECHO_PIN, INPUT); //Пин echo установливаем на считывание тока.
}

void loop() {
    int range = getRange(TRIG_PIN, ECHO_PIN); //Получаем расстояние.

    //Отправляем на компьютер расстояние. Функция print в отличие от функции println не добавляет в конец строки
    //переход на новую строку (и не отправляет эту строку на компьютер, а хранит в буфере).
    Serial.print("Расстояние: ");

    //Так мы можем собрать необходимую нам строку. Добавляем расстояние.
    Serial.print(range);

    //И отправляем эту строку с помощью функции println на компьютер.
    //То есть при расстояние 230 см на компьютер будет отослана строка в виде: Расстояние 230 см
    Serial.println(" см");

    //Делаем задержку на 100 (можно меньше) для того, чтобы нам точно не мешал предыдущий сигнал.
    delay(100);
}

/**
 * Функция возвращает расстояние от дальномера.
 *
 * @param trig - пин к которому подключён выход дальномера trig,
 * @param echo - пин к которому подключён выход дальномера echo.
 *
 * @return расстояние до ближайшего объекта от дальномера
 */
int getRange(int trig, int echo) {
    digitalWrite(trig, HIGH);
    delayMicroseconds(2000);
    digitalWrite(trig, LOW);
    int duration = pulseIn(echo, HIGH);
    int distance = (duration/2) / 29.1;
  
    return distance;
}