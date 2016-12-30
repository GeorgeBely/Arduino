#include <IRremote.h>

/** Подключаем ИК приёмник к пину 11 */
#define I_REMOTE_PIN 11
#define LED_PIN 6


boolean ledValue = false; 
int ledLevel = 255;

/** С помощью этих переменных будем обрабатывать входные данные на ИК приёмник */
IRrecv irrecv(I_REMOTE_PIN);
decode_results remoteValue;


void setup() {
    Serial.begin(9600);

    // Инициализируем переменную irrecv
    irrecv.enableIRIn();

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    String value = getRemoteValue();
    if (value != "") {
        Serial.println(value);

        if (value == "on") {
            ledValue = !ledValue;
            if (ledValue) {
                analogWrite(LED_PIN, ledLevel);
            } else {
                digitalWrite(LED_PIN, LOW);
            }
        }
     
        if (value == "-") {
            if (ledLevel <= 10) {
                ledLevel = 0;
            } else {
                ledLevel = ledLevel - 10;
            }
            analogWrite(LED_PIN, ledLevel);
        }
     
        if (value == "+") {
            if (ledLevel >= 245) {
                ledLevel = 255;
            } else {
                ledLevel = ledLevel + 10;
            }
            analogWrite(LED_PIN, ledLevel);
        }
    }
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