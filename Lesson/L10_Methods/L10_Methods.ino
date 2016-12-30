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

/**
 * Функция считывает температуру. Данная функция рассчитана на использование термометра lm35.
 *
 * @param pin - номер пина к которому подключён термометр.
 *
 * @return температуру. От 0 и выше.
 */
int getTerm(int pin) {
    return (125 * analogRead(pin)) >> 8;
}

/**
 * ИК значения кнопок нужно сначала считать и записать соответствия.
 *
 * @return наименование нажатой кнопки на пульте.
 */
String getRemoteValue() {
    if (irrecv.decode(&remoteValue)) {
        irrecv.resume();
        switch(remoteValue.value) {
            case 4294967295: return "";
            case 16753245: return "on";
            case 16769565: return "menu";
            case 16720605: return "test";
            case 16712445: return "+";
            case 16761405: return "back";
            case 16769055: return "previous";
            case 16754775: return "play";
            case 16748655: return "next";
            case 16738455: return "0";
            case 16750695: return "-";
            case 16756815: return "c";
            case 16724175: return "1";
            case 16718055: return "2";
            case 16743045: return "3";
            case 16716015: return "4";
            case 16726215: return "5";
            case 16734885: return "6";
            case 16728765: return "7";
            case 16730805: return "8";
            case 16732845: return "9";
        }
    }
    return "";
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

/**
 * @return текущее время с модуля времени.
 */
String getTime() {
    Time t = rtc.time();

    String result = "";

    result += t.yr;
    result += "-";
    result += t.mon;
    result += "-";
    result += t.date;
    result += "  ";
    result += t.hr;
    result += ":";
    result += t.min;
    result += ":";
    result += t.sec;
    result += "  (";
    result += t.day;
    result += ")";

    return result;
}
