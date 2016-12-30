/** Управление движением вперёд */
#define UP    6

/** Управление движением назад */
#define DOWN  7

/** Управление движением влево */
#define LEFT  8

/** Управление движением вправо */
#define RIGHT 9

/** Будем использовать эту переменную, чтобы двигать машику сначала вперёд, а затем назад */
boolean moveUp = true;


void setup() {
    pinMode(UP, OUTPUT);
    pinMode(DOWN, OUTPUT);
    pinMode(LEFT, OUTPUT);
    pinMode(RIGHT, OUTPUT);
}

void loop() {  
    digitalWrite(UP, moveUp);
    digitalWrite(DOWN, !moveUp);
    digitalWrite(LEFT, moveUp);
    digitalWrite(RIGHT, !moveUp);

    moveUp = !moveUp;
    delay(1000);
}
