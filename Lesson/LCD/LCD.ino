#include <LiquidCrystal.h>

/** С помощью этой переменной будем отрисовывать данные на дисплей */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


void setup() {
    lcd.begin(16, 2);
}

void loop() {
    lcdPrint("number", 0, 0);
    lcdPrint("1234567890", 1, 0);
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
    lcd.setCursor(startSymbol, numberStr); // Переводим курсор на строку {numberStr} на {startSymbol} символ
    lcd.print("                ");
    lcd.print(msg); // Отрисовываем строку на дисплей
}
