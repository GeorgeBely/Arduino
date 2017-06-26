#include <Keypad.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>
#include "gsm/gsm.h"

/** Номера пинов Arduino, к которым подключается модуль реального времени */
#define CLK_PIN 13
#define DAT_PIN 12
#define RST_PIN 11

#define ROWS 4
#define COLS 4
#define YES_BUTTON_PIN 9
#define NO_BUTTON_PIN 10

#define GSM_RX_PIN 7
#define GSM_TX_PIN 8


// 0, 1, 11, 12, 13, A2, A3


/**
 * С помощью этой переменной будем отрисовывать данные на дисплей
 * Параметры     Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity  - почему так задаюся хз((
 * LCD интерфейс нужно подключать SDA -> A4(SDA)   SCL -> A5(SCL)
 */
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

/** Задаём символы соответствующие кнопкам клавиатуры */
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

char letters[ROWS - 1][COLS][5] = {
        {{' ', '.', '-', ':', '1'}, {'a', 'b', 'c', '2', '2'}, {'d', 'e', 'f', '3', '3'}},
        {{'g', 'h', 'i', '4', '4'}, {'j', 'k', 'l', '5', '5'}, {'m', 'n', 'o', '6', '6'}},
        {{'p', 'q', 'r', 's', '7'}, {'t', 'u', 'v', '8', '8'}, {'w', 'x', 'y', 'z', '9'}}
};

/** Задаём соответствыя, к каким пинам подключена строка. Можно использовать как аналоговые пины, так и цифровые. */
byte rowPins[ROWS] = {2, 3, 4, 5};

/** Задаём соответствыя, к каким пинам подключён столбец. Можно использовать как аналоговые пины, так и цифровые. */
byte colPins[COLS] = {A1, A0, 6};

/** С помощью этой переменной будем получать и обрабатывать данные с кейпада */
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

/** С помощью этой переменной будем получкать данные с модуля */
DS1302 rtc(RST_PIN, DAT_PIN, CLK_PIN);

/** Строку strNumber используем для набора номера телефона */
String strNumber = "";

/** В строке currStr будем хранить текущую строку, которую передает нам плата GSM */
String currStr = "";

/** Переменная принимает значение True, если текущая строка является сообщением */
boolean isStringMessage = false;

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


void setup() {
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.setBacklight(HIGH); // Включаем подсветку экрана
    lcd.home(); // Переместить курсор на начало

    pinMode(YES_BUTTON_PIN, INPUT);
    pinMode(NO_BUTTON_PIN, INPUT);
}

void loop() {
    if (monitoringGSM())
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
        lcdPrint("Home", 0, 6);
        lastPageId = 0;
        currentTime = "";
    }

    String time = getTime();
    if (time != "" && currentTime != time) {
        currentTime = time;
        lcdPrint(time, 1, 0);
    }
}

bool saveContact() {
    if (pageId != 2) {
        return false;
    }

    if (lastPageId != pageId) {
        lcdPrint(strNumber, 1, 0);
        lcdPrint("Name: ", 0, 0);
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
    if (key != NO_KEY) {
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
        lcdPrint("set number", 0, 3);
        lcdPrint("", 1, 3);
        lastPageId = 1;
        cursorTime = 0;
    }

    char key = keypad.getKey();
    if (key != NO_KEY) {
        if (key == '#') {
            strNumber = "set number";
            lcdPrint("set number", 0, 3);
            lcdPrint("", 1, 3);
       /* } else if (key == '*') {
            if (strNumber[0] == '8')
                strNumber = "+7" + strNumber.substring(1, strNumber.length());
            else if (strNumber[0] == '7')
                strNumber = "+" + strNumber;
            callTo(strNumber);
            lcd.noCursor();
       */ } else if (key == '*') {
            pageId = 2;
        } else {
            if (strNumber == "set number") {
                strNumber = "";
            }
            strNumber += key;
            lcdPrint(strNumber, 1, 3);
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

/**
 * Отрисовывает строку на дисплей
 *
 * @param msg       - строка
 * @param numberStr - номер строки на которой отобразить "msg"
 *                    (0 первая строка, 1 вторая строка)
 */
void lcdPrint(String msg, int numberStr, int startSymbol) {
    lcd.setCursor(0, numberStr);
    lcd.print("                ");
    lcd.setCursor(startSymbol, numberStr);
    lcd.print(msg);
}
