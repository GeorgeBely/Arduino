#include "Arduino.h"
#include "LCDMobile.h"
#include "../../lib/NewliquidCrystal_1.3.4/NewliquidCrystal/LCD.h"
#include "../../lib/NewliquidCrystal_1.3.4/NewliquidCrystal/LiquidCrystal_I2C.h"


/**
 * С помощью этой переменной будем отрисовывать данные на дисплей
 * Параметры     Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity  - почему так задаюся хз((
 * LCD интерфейс нужно подключать SDA -> A4(SDA)   SCL -> A5(SCL)
 */
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);



LCDMobile::LCDMobile(uint8_t rxPin, uint8_t txPin) {
    lcd.begin(16, 2);
    lcd.setBacklight(HIGH); // Включаем подсветку экрана
    lcd.home(); // Переместить курсор на начало
}


/**
 * Отрисовывает строку на дисплей
 *
 * @param msg       - строка
 * @param numberStr - номер строки на которой отобразить "msg"
 *                    (0 первая строка, 1 вторая строка)
 */
void LCDMobile::lcdPrint(String msg, uint8_t numberStr, uint8_t startSymbol) {
    lcd.setCursor(0, numberStr);
    lcd.print("                ");
    lcd.setCursor(startSymbol, numberStr);
    lcd.print(msg);
}


void LCDMobile::cursor() {
    lcd.cursor();
}

void LCDMobile:: noCursor() {
    lcd.noCursor();
}
