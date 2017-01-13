#include <VirtualWire.h>
#include "DHT.h"

/** Подключаем передатчик к пину 11 */
#define RADIO_TRANSMITTER_PIN 11

/** Подключаем термометр к пину 2 */
#define DHT_PIN 2

/** Подключаем датчик дождя к аналоговому пину 4 */
#define RAIN_PIN A4

/** Подключаем фоторезистор к аналоговому пину 5 */
#define PHOTO_PIN A5


/** С помощью этой переменной будем получать и обрабатывать данные с термометра */
DHT dht(DHT_PIN, DHT21);


void setup() {
    vw_set_ptt_inverted(true); // Необходимо для DR3100
    vw_setup(2000); // Устанавливаем скорость передачи (бит/с)
    vw_set_tx_pin(RADIO_TX_PI);

    dht.begin();
}

void loop(void) {  
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    int r = (100.0 / 1023.0) * (1023 -analogRead(RAIN_PIN));
    int p = (100.0 / 1023.0) * (1023 -analogRead(PHOTO_PIN));

    String str = "r";
    str += r;
    str += "|p";
    str += p;
    str += "|h";
    str += (int) h;
    str += "|t";
    str += (int) t;

    sendMessageByRadio(str);

    delay(1000);
}

/**
 * Функция отправки сообщения по радио
 *
 * @param str сообщение
 */
void sendMessageByRadio(String str) {
    String message = "$";
    message += str;
    message += "$";
    char msg[255];
    message.toCharArray(msg, 255);

    vw_send((uint8_t *) msg, strlen(msg));
    vw_wait_tx(); // Ждем пока передача будет окончена
    delay(200);
}