#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>


/**
 * С помощью этой переменной будем отрисовывать данные на дисплей
 * Параметры     Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity  - почему так задаюся хз((
 * LCD интерфейс нужно подключать SDA -> A4(SDA)   SCL -> A5(SCL)
 */
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

/** Счётчик */
int count = 1;


void setup() {
    lcd.begin(16, 2); // Подключаем экран с двумя рядам по 16 символов
    lcd.setBacklight(HIGH); // Включаем подсветку экрана
    lcd.home(); // Переместить курсор на начало
}

void loop() {
    lcdPrint("Hello World!", 0, 2);

    char sCount[5];
    itoa(count, sCount, 10);
    lcdPrint(sCount, 1, 7);

    count++;
    delay(1000);
}

/**
 * Отрисовывает строку на дисплей
 *
 * @param msg         - строка
 * @param numberStr   - номер строки на которой отобразить "msg"
 *                      (0 первая строка, 1 вторая строка)
 * @param startSymbol - номер строки на которой отобразить "msg"
 *                      (0 первая строка, 1 вторая строка)
 */
void lcdPrint(String msg, int numberStr, int startSymbol) {
    lcd.setCursor(0, numberStr); // Переводим курсор на строку {numberStr} на {startSymbol} символ
    lcd.print("                ");
    lcd.setCursor(startSymbol, numberStr); // Переводим курсор на строку {numberStr} на {startSymbol} символ
    lcd.print(msg); // Отрисовываем строку на дисплей
}
