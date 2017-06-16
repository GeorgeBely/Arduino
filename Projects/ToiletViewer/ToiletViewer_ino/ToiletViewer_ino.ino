#include <VirtualWire.h>

/** Подключаем передатчик к пину 12 */
#define RADIO_TX_PI 9

/** Подключаем дальномер */
#define ECHO_PIN 11
#define TRIG_PIN 13

#define MOVE_SENSOR_PIN 6

#define MAX_DISTANCE 150
#define MAX_RANGE_COUNT 4


int rangeCount = 0;

void setup() {
    vw_set_ptt_inverted(true);
    vw_setup(2000);
    vw_set_tx_pin(RADIO_TX_PI);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.begin(9600);
}

void loop() {
    boolean moveValue = isMoveEnable(MOVE_SENSOR_PIN);
    if (moveValue) {
        sendMessageByRadio("1");
    } else {
        int range = getRange(TRIG_PIN, ECHO_PIN);
        if (range < MAX_DISTANCE) {
            if (rangeCount == MAX_RANGE_COUNT) {
                sendMessageByRadio("1");
            } else {
                rangeCount++;
            }
        } else {
            rangeCount = 0;
        }
    }
    delay(50);
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

/**
 * Функция отправки сообщения по радио
 *
 * @param str сообщение
 */
void sendMessageByRadio(String str) {
    Serial.println(str);

    String message = "$";
    message += str;
    message += "$";
    char msg[255];
    message.toCharArray(msg, 255);

    vw_send((uint8_t *) msg, strlen(msg));
    vw_wait_tx(); // Ждем пока передача будет окончена
    delay(200);
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

