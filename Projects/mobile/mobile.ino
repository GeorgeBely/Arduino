#include <Keypad.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include <DS1302.h>

/** Номера пинов Arduino, к которым подключается модуль реального времени */
#define CLK_PIN 13
#define DAT_PIN 12
#define RST_PIN 11

#define ROWS 4
#define COLS 4
#define YES_BUTTON_PIN 9
#define NO_BUTTON_PIN 10

// 0, 1, 11, 12, 13, A2, A3


/**
 * С помощью этой переменной будем отрисовывать данные на дисплей
 * Параметры     Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity  - почему так задаюся хз((
 * LCD интерфейс нужно подключать SDA -> A4(SDA)   SCL -> A5(SCL)
 */
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

/** заводим Serial-соединение с GPRS-Shield на 7 и 8 цифровых входах */
SoftwareSerial gprsSerial(7, 8);

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

    // GPRS Shield общается по умолчанию на скорости 19200 бод
    gprsSerial.begin(19200);
    // Настраиваем приём сообщений с других устройств
    // Между командами даём время на их обработку
    gprsSerial.print("AT+CMGF=1\r");
    delay(300);
    gprsSerial.print("AT+IFC=1, 1\r");
    delay(300);
    gprsSerial.print("AT+CPBS=\"SM\"\r");
    delay(300);
    gprsSerial.print("AT+CNMI=1,2,2,1,0\r");
    delay(300);
    gprsSerial.println("AT+CLIP=1");
    delay(500);

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
 * Функция опрашивает GSM модуль на наличие входящего звонка или СМС.
 * При их наличии реагирует должным образом.
 * Для ответа используется функция answerToCall()
 * Для прочтения СМС используется функция readSMS()
 */
bool monitoringGSM() {
    touch();

    if (!gprsSerial.available())
        return false;

    // Считываем очередной символ с платы
    char currSymbol = gprsSerial.read();

    if ('\r' == currSymbol) {
        if (currStr.startsWith("+CMT")) {
            //если текущая строка начинается с "+CMT",
            //то следующая строка является сообщением
            isStringMessage = true;
        } else if (isStringMessage) {
            readSMS(currStr);
            isStringMessage = false;
        } else if (currStr == "RING") {
            currStr = "";
            return true;
        } else if (currStr.startsWith("+CLIP")) {
            // Получен символ перевода строки, это значит, что текущее
            // сообщение от платы завершено и мы можем на него отреагировать.
            // Если текущая строка - это RING, то значит, нам кто-то звонит
            answerToCall(currStr.substring(8, 20));
            Serial.println(currStr);
        }
        currStr = "";
    } else if (currSymbol != '\n') {
        // Дополняем текущую команду новым сиволом
        // При этом игнорируем второй символ в последовательности переноса
        // строки: \r\n
        currStr += String(currSymbol);
    }

    return true;
}

/**
 * Ответ на входящий звонок
 */
void answerToCall(String number) {
    lcdPrint("incoming call", 0, 0);
    lcdPrint(number, 1, 0);

    if (number == "+79507775731")
        gprsSerial.println("ATA");
    else {
        char key = keypad.getKey();

        if (key == '*')
            gprsSerial.println("ATA");
        else if (key == '#')
            gprsSerial.println("AT+CHUP");
    }
}

/**
 * Cразу после вызова функции начинаем звонить по заданному номеру
 *
 * @param number - номер телефона в формате "+79XXXXXXXXX"
 */
void callTo(String number) {
    lcdPrint("call to", 0, 0);
    lcdPrint(number, 1, 0);

    gprsSerial.print("ATD + ");
    gprsSerial.print(number);
    gprsSerial.println(";");
}

/**
 * Разбираем СМС.
 *
 * @param message - текст сообщения
 */
void readSMS(String message) {
    Serial.println(message);
    lcdPrint("Incoming message", 0, 0);
    lcdPrint(message, 1, 0);
    // Пересылаем полученное сообщение
    sendSMS(message, "+79507775731");
}

/**
 * Отправляем СМС сообщение на указаный номер.
 *
 * @param message - текст сообщения
 * @param number - номер телефона в формате "+79XXXXXXXXX"
 */
void sendSMS(String message, String number) {
    // Устанавливает текстовый режим для SMS-сообщений
    gprsSerial.print("AT+CMGF=1\r");
    delay(100); // даём время на усваивание команды

    // Устанавливаем адресата: телефонный номер в формате "+79XXXXXXXXX"
    gprsSerial.print("AT + CMGS = \"");
    gprsSerial.print(number);
    gprsSerial.println("\"");
    delay(100);

    // Пишем текст сообщения
    gprsSerial.println(message);
    delay(1000);

    // Отправляем Ctrl+Z, обозначая, что сообщение готово
    gprsSerial.println((char)26);
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

/**
 * Функция провоцирует поддержание коммуникации с платой даже если
 * та была перезагружена без перезагрузки Arduino
 */
int updateTime = 0;
void touch() {
    if (millis() >= updateTime) {
        gprsSerial.println("AT");
        updateTime += 5000;
    }
}