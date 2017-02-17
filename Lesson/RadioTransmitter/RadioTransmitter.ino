#include <VirtualWire.h>

/** Подключаем передатчик к пину 12 */
#define RADIO_TX_PI 12


void setup() {
    vw_set_ptt_inverted(true); // Необходимо для DR3100
    vw_setup(2000); // Устанавливаем скорость передачи (бит/с)
    vw_set_tx_pin(RADIO_TX_PI);
}

/**
 * Будем циклично передавать числа от 0 до 300
 */
void loop() {
    for (int i = 0; i < 300; i++) {
        String strMsg = "";
        strMsg += i;
        sendMessageByRadio(strMsg);
    }
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

