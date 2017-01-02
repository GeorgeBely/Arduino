/** Подключаем светодиод */
#define LED_PIN 13

/** Подключаем buzzer (пищалка) */
#define SPEAKER_PIN 3

/** Ноты */
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880


void setup() {
    pinMode(LED_PIN, OUTPUT);
    pinMode(SPEAKER_PIN, OUTPUT);
}

void loop() {
    march();
}

/**
 * Проигрываем имперский марш
 */
void march() {
    beep(a, 500);
    beep(a, 500);
    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);

    beep(a, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 1000);

    beep(eH, 500);
    beep(eH, 500);
    beep(eH, 500);
    beep(fH, 350);
    beep(cH, 150);

    beep(gS, 500);
    beep(f, 350);
    beep(cH, 150);
    beep(a, 1000);

    beep(aH, 500);
    beep(a, 350);
    beep(a, 150);
    beep(aH, 500);
    beep(gSH, 250);
    beep(gH, 250);

    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);
    delay(250);
    beep(aS, 250);
    beep(dSH, 500);
    beep(dH, 250);
    beep(cSH, 250);

    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);
    delay(250);
    beep(f, 125);
    beep(gS, 500);
    beep(f, 375);
    beep(a, 125);

    beep(cH, 500);
    beep(a, 375);
    beep(cH, 125);
    beep(eH, 1000);

    beep(aH, 500);
    beep(a, 350);
    beep(a, 150);
    beep(aH, 500);
    beep(gSH, 250);
    beep(gH, 250);

    beep(fSH, 125);
    beep(fH, 125);
    beep(fSH, 250);
    delay(250);
    beep(aS, 250);
    beep(dSH, 500);
    beep(dH, 250);
    beep(cSH, 250);

    beep(cH, 125);
    beep(b, 125);
    beep(cH, 250);
    delay(250);
    beep(f, 250);
    beep(gS, 500);
    beep(f, 375);
    beep(cH, 125);

    beep(a, 500);
    beep(f, 375);
    beep(c, 125);
    beep(a, 1000);
}

/**
 * Проигрывает ноту
 *
 * @param frequencyInHertz   временное значение ноты
 * @param timeInMilliseconds время проигрывания
 */
void beep(int frequencyInHertz, long timeInMilliseconds) {
    digitalWrite(LED_PIN, HIGH);

    int x;
    long delayAmount = (long) (1000000 / frequencyInHertz);
    long loopTime = (long) ((timeInMilliseconds * 1000) / (delayAmount * 2));
    for (x = 0; x < loopTime; x++) {
        digitalWrite(SPEAKER_PIN, HIGH);
        delayMicroseconds(delayAmount);
        digitalWrite(SPEAKER_PIN, LOW);
        delayMicroseconds(delayAmount);
    }

    digitalWrite(LED_PIN, LOW);

    delay(20);
}

