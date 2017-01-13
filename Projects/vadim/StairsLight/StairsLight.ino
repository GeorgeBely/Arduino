/** Номер пина Arduino, к которому подключено реле */
#define RELAY_PIN 12

/** Номер пина к которому подключён датчик движения */
#define MOVE_SENSOR_PIN 3

/** Устанавливаем максимальное колличество секунд, при которых свет будет гореть без наличия движения */
#define MAX_SEK_USE_LED_COUNT 15

/** Переменная хранит время оставшиеся до отключения света */
double useLedTime = 0;


void setup() {
    //Запускаем arduino на порте 9600, для общения с компьютером
    Serial.begin(9600);

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(MOVE_SENSOR_PIN, INPUT);
}

void loop() {
    boolean haveMove = isMoveEnable(MOVE_SENSOR_PIN);

    if (haveMove) {
        digitalWrite(RELAY_PIN, false);
        useLedTime = MAX_SEK_USE_LED_COUNT;
    } else {
        if (useLedTime <= 0) {
            digitalWrite(RELAY_PIN, true);
        } else {
            useLedTime -= 0.1;
        }
    }

    delay(100);
}

/**
 * Функция определяет наличие движения с помощью датчика движения
 *
 * @param moveSensorPin - намер пина, к которому подключён датчик движения
 * prevState - переменная, которая хранит предыдущее значение наличия движения.
 *
 * @return {true}, если датчик зафиксировал движение
 */
int prevState = LOW;
boolean isMoveEnable(int moveSensorPin) {
    boolean val = digitalRead(moveSensorPin);
    if (val != prevState) {
        prevState = val;
        return true;
    }
    return false;
}