#include <Wire.h>
#include <DS1302.h>
#include "GSM/GSM.h"
#include "LCD/LCDMobile.h"
#include "Keypad/KeypadMobile.h"
#include "Arduino.h"

/** Номера пинов Arduino, к которым подключается модуль реального времени */
#define CLK_PIN 13
#define DAT_PIN 12
#define RST_PIN 11

#define YES_BUTTON_PIN 9
#define NO_BUTTON_PIN 10

#define GSM_RX_PIN 7
#define GSM_TX_PIN 8


/** Задаём соответствыя, к каким пинам подключена строка. Можно использовать как аналоговые пины, так и цифровые. */
byte rowPins[] = {2b, 3b, 4b, 5b};

/** Задаём соответствыя, к каким пинам подключён столбец. Можно использовать как аналоговые пины, так и цифровые. */
byte colPins[] = {A1, A0, 6};

// 0, 1, 11, 12, 13, A2, A3


char letters[ROWS - 1][COLS][5] = {
        {{' ', '.', '-', ':', '1'}, {'a', 'b', 'c', '2', '2'}, {'d', 'e', 'f', '3', '3'}},
        {{'g', 'h', 'i', '4', '4'}, {'j', 'k', 'l', '5', '5'}, {'m', 'n', 'o', '6', '6'}},
        {{'p', 'q', 'r', 's', '7'}, {'t', 'u', 'v', '8', '8'}, {'w', 'x', 'y', 'z', '9'}}
};



/** С помощью этой переменной будем получкать данные с модуля */
DS1302 rtc(RST_PIN, DAT_PIN, CLK_PIN);

/** Строку strNumber используем для набора номера телефона */
String strNumber = "";

/**
 * Хранит id текущей отображаемой страницы.
 * 0 - главная
 * 1 - набор номера
 * 2 - сохранение контакта
 */
int pageId = 0;

/**
 * Хранит id предыдущей отображаемой страницы.
 */
int lastPageId = -1;


String catalogue[0];


int cursorTime = 0;
String currentTime = "";

int letterIndex = 0;
int lastLetterCount = 0;
String nameStr = "";
char lastNameChar = ' ';


GSMMobile gsm(GSM_RX_PIN, GSM_TX_PIN);

LCDMobile lcd(A4, A0);

KeypadMobile keypad(rowPins, colPins);

void setup() {
    Serial.begin(9600);

    pinMode(YES_BUTTON_PIN, INPUT);
    pinMode(NO_BUTTON_PIN, INPUT);
}

void loop() {
    if (gsm.monitoringGSM())
        return;
    else if (digitalRead(NO_BUTTON_PIN)) {
        lcd.noCursor();
        pageId = 0;
    } else if (dialingNumber()) {
        return;
    } else if (saveContact()) {
        return;
    }
    homePage();

    cursorTime += 10;
    delay(10);
}

void homePage() {
    if (pageId != 0)
        return;

    if (digitalRead(YES_BUTTON_PIN)) {
        pageId = 1;
        return;
    }

    if (lastPageId != pageId) {
        lcd.lcdPrint("Home", 0, 6);
        lastPageId = 0;
        currentTime = "";
    }

    String time = getTime();
    if (time != "" && currentTime != time) {
        currentTime = time;
        lcd.lcdPrint(time, 1, 0);
    }
}

bool saveContact() {
    if (pageId != 2) {
        return false;
    }

    if (lastPageId != pageId) {
        lcd.lcdPrint(strNumber, 1, 0);
        lcd.lcdPrint("Name: ", 0, 0);
        lastPageId = 2;
        cursorTime = 0;
        lastLetterCount = -100;
        nameStr = 0;
    }

    if (cursorTime < 500)
        lcd.cursor();
    else if (cursorTime < 1000)
        lcd.noCursor();
    else
        cursorTime = 0;

    char key = keypad.getKey();
    if (key != keypad.NO_KEY) {
        if (lastLetterCount)
            if (key == '#') {

            }
    }



}

/**
 * Обрабатывает страницу набора номера.
 *
 * @return {true}, если пользователь на странице набра номера
 */
bool dialingNumber() {
    if (pageId != 1) {
        return false;
    }
    if (cursorTime < 500)
        lcd.cursor();
    else if (cursorTime < 1000)
        lcd.noCursor();
    else
        cursorTime = 0;

    if (lastPageId != pageId) {
        strNumber = "set number";
        lcd.lcdPrint("set number", 0, 3);
        lcd.lcdPrint("", 1, 3);
        lastPageId = 1;
        cursorTime = 0;
    }

    char key = keypad.getKey();
    if (key != NO_KEY) {
        if (key == '#') {
            strNumber = "set number";
            lcd.lcdPrint("set number", 0, 3);
            lcd.lcdPrint("", 1, 3);
            /* } else if (key == '*') {
                 if (strNumber[0] == '8')
                     strNumber = "+7" + strNumber.substring(1, strNumber.length());
                 else if (strNumber[0] == '7')
                     strNumber = "+" + strNumber;
                 GSM.callTo(strNumber);
                 lcd.noCursor();
            */ } else if (key == '*') {
            pageId = 2;
        } else {
            if (strNumber == "set number") {
                strNumber = "";
            }
            strNumber += key;
            lcd.lcdPrint(strNumber, 1, 3);
        }
    }

}


/**
 * @return текущее время с модуля времени.
 */
String getTime() {
    Time t = rtc.time();

    if (t.yr == 2000) {
        return "";
    }
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

    return result;
}
