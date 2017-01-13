#include <VirtualWire.h>
#include <Wire.h>
#include <EEPROM.h>
#include "TM1637.h"


/** Номера пинов Arduino, к которым подключается индикатор */
#define DISPLAY_CLK_PIN 10  
#define DISPLAY_DIO_PIN 12


/** С помощью этой переменной будем отрисовывать данные на дисплей */
TM1637 display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);

boolean point = false;


void setup() {
    Serial.begin(9600);

    vw_set_ptt_inverted(true); // Необходимо для DR3100
    vw_setup(2000); // Задаем скорость приема
    vw_rx_start(); // Начинаем мониторинг эфира

    //Включаем и настраиваем индикатор
    display.set();
    display.init();
}

void loop() {
    String result = readMessageByRadio();
    if (result != "") {
        setDisplayValue(atoi(result.c_str()), point);
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

/**
 * Функция отображает переданное число на светодиодном индикаторе
 *
 * @param value    - число, которое нужно отобразить (4 значное или меньше)
 * @param usePoint - если {true}, то отображать двоеточие между числами
 */
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
    display.point(usePoint);
}