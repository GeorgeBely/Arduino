
String msg;

/**
 * Создаём Serial подключение на порту 9600
 */
void setup() {
    Serial.begin(9600);
}

void loop() {
    msg = "";
    while (Serial.available()) {
        msg += Serial.readString(); // read the incoming data as string
    }

    if (msg != "") {
        Serial.println(msg);
    }
}