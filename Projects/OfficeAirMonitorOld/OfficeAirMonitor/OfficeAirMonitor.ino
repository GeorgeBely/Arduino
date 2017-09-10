#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"


/** Подключаем термометр к пину 2 */
#define DHT_PIN 2

/** Подключаем датчик CO2 к аналоговому пину 0 */
#define CO2_PIN A0

/** Lkz Датчика AM2301 задаём: DHT21 */
#define DHTTYPE DHT21


/// The load resistance on the board
#define RLOAD 1.0

/// Parameters for calculating ppm of CO2 from sensor resistance
#define PARA 116.6020682
#define PARB 2.769034857

/// Parameters to model temperature and humidity dependence
#define CORA 0.00035
#define CORB 0.02718
#define CORC 1.39538
#define CORD 0.0018

/// Atmospheric CO2 level for calibration purposes
#define ATMOCO2 397.13


//#define RZERO_CALIBRATING_MASS_SIZE 50
//#define RZERO_CALIBRATING_COUNT 5


#define CYCLE_ITERATION_COUNT 30

/** С помощью этой переменной будем получать и обрабатывать данные с термометра */
DHT dht(DHT_PIN, DHTTYPE);


/**
 * С помощью этой переменной будем отрисовывать данные на дисплей
 * Параметры     Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity  - почему так задаюся хз((
 * LCD интерфейс нужно подключать SDA -> A4(SDA)   SCL -> A5(SCL)
 */
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int count = 0;
float humidityMass[CYCLE_ITERATION_COUNT];
float temperatureMass[CYCLE_ITERATION_COUNT];
float rZeroCO2Mass[CYCLE_ITERATION_COUNT];
double co2Mass[CYCLE_ITERATION_COUNT];
int analogCO2Mass[CYCLE_ITERATION_COUNT];

float lastCorrectHumidity = 0;
float lastCorrectTemperature = 0;
double lastCorrectCo2 = 0;
int lastCorrectAnalogCO2 = 0;
float lastCorrectRZero = 0;

int hr = 12;
int mn = 53;
int sk = 30;


void setup() {
    Serial.begin(9600);

    lcd.begin(16, 2); // Подключаем экран с двумя рядам по 16 символов
    lcd.setBacklight(HIGH); // Включаем подсветку экрана
    lcd.home(); // Переместить курсор на начало

    dht.begin();

    lcdPrint("Calibrating...", 0, 0);
    Serial.print("Calibrating CO2 sensor");
    for(int i = 0; i < 1; i++){
        Serial.println(i);
        delay(1000);
    }
    Serial.println("");
}

void loop() {
    float h = dht.readHumidity(); // Считываем влажность воздуха в процентах
    float t = dht.readTemperature(); // Считываем температуру в градусах

    int a = analogRead(A0);
    double CO2Tmp = getCorrectedPPM(a, t, h);
    float z = getCorrectedRZero(a, t, h);

    // проверяем, что данные корректны
    if (!isnan(t)) {
        lastCorrectTemperature = t;
    } else {
        Serial.println("Failed to read temperature from DHT");
    }
    if (!isnan(h)) {
        lastCorrectHumidity = h;
    } else {
        Serial.println("Failed to read humidity from DHT");
    }
    if (CO2Tmp > 10) {
        lastCorrectCo2 = CO2Tmp;
    } else {
        Serial.println("Failed to read from CO2 sensor");
    }
    if (a > 10) {
        lastCorrectAnalogCO2 = a;
    } else {
        Serial.println("Failed to read analog CO2 sensor");
    }
    if (z > 10) {
        lastCorrectRZero = z;
    } else {
        Serial.println("Failed to read from rZero");
    }

    if (count >= CYCLE_ITERATION_COUNT) {
        float temperature = 0;
        float humidity = 0;
        double co2 = 0;
        int analog = 0;
        float rzero = 0;
        for (int i = 0; i < CYCLE_ITERATION_COUNT; i++) {
            temperature += temperatureMass[i];
            humidity += humidityMass[i];
            co2 += co2Mass[i];
            analog += analogCO2Mass[i];
            rzero += rZeroCO2Mass[i];
        }
        temperature = temperature/CYCLE_ITERATION_COUNT;
        humidity = humidity/CYCLE_ITERATION_COUNT;
        co2 = co2/CYCLE_ITERATION_COUNT;
        analog = analog/CYCLE_ITERATION_COUNT;
        rzero = rzero/CYCLE_ITERATION_COUNT;


        Serial.print("time: ");
        Serial.print(hr);
        Serial.print(":");
        Serial.print(mn);
        Serial.print(":");
        Serial.print(sk);
        Serial.print("\t");

        Serial.print("RZERO: ");
        Serial.print(rzero);
        Serial.print("\t");

        Serial.print("A: ");
        Serial.print(analog);
        Serial.print("\t");

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.print(" %\t");

        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.print(" *C\t");

        Serial.print("CO2: ");
        Serial.print(co2);
        Serial.println(" ppm");

        String firstStr = "Tem: ";
        firstStr += convertToStr(temperature);
        firstStr += " Hum: ";
        firstStr += convertToStr(humidity);
        String secondStr = "CO2: ";
        secondStr += convertToStr(co2);

        lcdPrint(firstStr, 0, 0);
        lcdPrint(secondStr, 1, 5);

        count = 0;
    } else {
        temperatureMass[count] = lastCorrectTemperature;
        humidityMass[count] = lastCorrectHumidity;
        rZeroCO2Mass[count] = lastCorrectRZero;
        co2Mass[count] = lastCorrectCo2;
        analogCO2Mass[count] = lastCorrectAnalogCO2;
        count++;
    }

    updateTime();
 //   updateRZero(a, t, h);
    delay(880);
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
    lcd.setCursor(startSymbol, numberStr); // Переводим курсор на строку {numberStr} на {startSymbol} символ
    lcd.print(msg); // Отрисовываем строку на дисплей
}

String convertToStr(double value) {
    char sCount[5];
    itoa(value, sCount, 10);

    return sCount;
}


/// Calibration resistance at atmospheric CO2 level
float rZero = 65.00;
//float rZeroMass[RZERO_CALIBRATING_MASS_SIZE];;
//float rZeroEndMass[RZERO_CALIBRATING_COUNT];
//int rZeroCount = 0;
//int rZeroEndCount = 0;

float getCorrectionFactor(float t, float h) {
    return CORA * t * t - CORB * t + CORC - (h-33.)*CORD;
}

float getResistance(int val) {
    return ((1023./(float)val) * 5. - 1.)*RLOAD;
}

float getCorrectedResistance(int val, float t, float h) {
    return getResistance(val)/getCorrectionFactor(t, h);
}

float getPPM(int val) {
    return PARA * pow((getResistance(val)/rZero), -PARB);
}

float getCorrectedPPM(int val, float t, float h) {
    return PARA * pow((getCorrectedResistance(val, t, h)/rZero), -PARB);
}

float getRZero(int val) {
    return getResistance(val) * pow((ATMOCO2/PARA), (1./PARB));
}

float getCorrectedRZero(int val, float t, float h) {
    return getCorrectedResistance(val, t, h) * pow((ATMOCO2/PARA), (1./PARB));
}


void updateRZero(int val, float t, float h) {
//    if (hr != 3) {
//      return;
//    }
//    if (rZeroCount >= RZERO_CALIBRATING_MASS_SIZE) {
//        float summ = 0.0;
//        for (int i = 0; i < RZERO_CALIBRATING_MASS_SIZE; i++) {
//            summ += rZeroMass[i];
//        }
//        if (rZeroEndCount >= RZERO_CALIBRATING_COUNT) {
//            float summEnd = 0.0;
//            for (int i = 0; i < RZERO_CALIBRATING_COUNT; i++) {
//                summEnd += rZeroEndMass[i];
//            }
//            rZero = summEnd/rZeroEndCount;
//            Serial.print("rZero: ");
//            Serial.println(rZero);
//            rZeroEndCount = 0;
//        } else {
//            rZeroEndMass[rZeroEndCount] = summ/rZeroCount;
//            rZeroEndCount++;
//        }
//        rZeroCount = 0;
//    } else {
//        rZeroMass[rZeroCount] = getCorrectedRZero(val, t, h);
//        rZeroCount++;
//    }
}

void updateTime() {
    sk += 1;
    if (sk == 60) {
      mn += 1;
      sk = 0; 
    }
    if (mn == 60) {
      hr += 1;
      mn = 0; 
    }
    if (hr == 24) {
      hr = 0;
    }
}





