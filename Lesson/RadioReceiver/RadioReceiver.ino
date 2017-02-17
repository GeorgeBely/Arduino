#include <VirtualWire.h>

/** Подключаем приёмник к пину 11 */
#define RADIO_RX_PI 11


void setup() {
    Serial.begin(9600);

    vw_set_ptt_inverted(true); // Необходимо для DR3100
    vw_set_rx_pin(RADIO_RX_PI);
    vw_setup(2000); // Задаем скорость приема
    vw_rx_start(); // Начинаем мониторинг эфира
}

void loop() {
    String result = readMessageByRadio();
    if (result != "") {
        Serial.println(result);
    }
}

/**
 * Принимает сообщение по радио. Сообщение должно начинаться и заканчиваться символом '$'
 *
 * @return строка принятая радио приёмником
 */
String readMessageByRadio() {
    uint8_t buf[VW_MAX_MESSAGE_LEN]; // Буфер для сообщения
    uint8_t buflen = VW_MAX_MESSAGE_LEN; // Длина буфера

    // Если принято сообщение
    if (vw_get_message(buf, &buflen)) {
        // Если сообщение адресовано не нам, выходим
        if (buf[0] != '$') {
            return "";
        }
    
        int i = 1;
        String result = "";
        while (buf[i] != '$') {
            char ch = buf[i];
            result += ch;
            i++;
        }
        return result;
    }
    return "";
}
