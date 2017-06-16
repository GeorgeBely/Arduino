#include <SD.h>

//https://arduino-info.wikispaces.com/SD-Cards

File myFile;

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

// открываем файл. Обратите внимание, что открывать несколько файлов параллельно нельзя.

// перед открытием нового файла, старый надо закрыть

    myFile = SD.open("test.txt", FILE_WRITE);

// если удалось открыть файл, записываем в него:

    if (myFile) {

        Serial.print("Writing to test.txt...");

        myFile.println("testing ololo pish pish");

// закрываем файл:

        myFile.close();

        Serial.println("done.");

    } else {

// если файл не открылся, выводим сообщение об ошибке:

        Serial.println("error opening test.txt");

    }

}

void loop() {

// после setup ничего не происходит

}