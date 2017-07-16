#include <SD.h>

//13 (SCK), 12 (MISO), 11 (MOSI), 10 (CS)

void setup() {
    Serial.begin(9600);
    Serial.print("Initializing SD card...");

    // на Ethernet шилде CS соответствует 4 пину. По умолчанию он установлен в режим output
    // обратите внимание, что если он не используется в качестве CS пина, SS пин на оборудовании
    // (10 на большинстве плат Arduino, 53 на Arduino Mega) надо оставить в режиме output.
    // иначе функции библиотеки SD library не будут работать.
    pinMode(10, OUTPUT);

    if (!SD.begin(10)) {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");
}

void loop() {
    for (int i = 0; i < 500; i++) {
        writeToFile("test.txt", convertToStr(i));
        writeToFile("test2.txt", convertToStr(i + 1));
        delay(500);
    }
}


bool writeToFile(String fileName, String text) {
    // открываем файл. Обратите внимание, что открывать несколько файлов параллельно нельзя.
    // перед открытием нового файла, старый надо закрыть
    File myFile = SD.open(fileName.c_str(), FILE_WRITE);

    // если удалось открыть файл, записываем в него:
    if (myFile) {
        Serial.print("Writing to ");
        Serial.print(fileName);
        Serial.println("...");

        myFile.println(text);

        // закрываем файл:
        myFile.close();

        Serial.print("Close file: ");
        Serial.println(fileName);

        return true;
    } else {
        // если файл не открылся, выводим сообщение об ошибке:
        Serial.print("error opening ");
        Serial.println(fileName);

        return false;
    }
}


String convertToStr(int value) {
    char sCount[5];
    itoa(value, sCount, 10);

    return sCount;
}