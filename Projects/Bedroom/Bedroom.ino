//Дальномеры для определения количества людей в комнате
int range1TrigPin = 13;
int range1EchoPin = 12;
int range2TrigPin = 8;
int range2EchoPin = 7;

int lightRedPin = 11;
int lightGreenPin = 10;
int lightBluePin = 9;

int windowPin = 6;

int relayLightDownPin = 5;
int relayLightUpPin = 4;
int relayTvPin = 0;
          
//1. Термометр уличный
//2. Термометр комнатный
//3. Фоторезистор
//4. Датчик дождя/снега
//5. Потенциометр основного света (красный)
//6. Потенциометр основного света (зелёный)
//7. Потенциометр основного света (синий)
//8. Потенциометр уровня основного света
int relayBoxAnalog = A0;                  
//Бокс реле для подключения к аналоговому выходу 0 
//несколькох датчиков.
int relayBox1 = 1;
int relayBox2 = 2;
int relayBox3 = 3

//Модуль реального времени
int clockDatePin = A5;
int clockTimePin = A4;
//Датчик шума
int microphonePin = A3;
//Пульт дистанционного управления
int distanceControl = A2;
//Датчик влажности почвы в растение
int soilMoisturePin = A1;


int peopleNumber;
int ledRedValue;
int ledGreenValue;
int ledBlueValue;


void setup() {
  Serial.begin(9600);
  pinMode(range1TrigPin, OUTPUT);
  pinMode(range1EchoPin, OUTPUT);
  pinMode(range2TrigPin, OUTPUT);
  pinMode(range2EchoPin, OUTPUT);
  pinMode(lightRedPin, OUTPUT);
  pinMode(lightGreenPin, OUTPUT);
  pinMode(lightBluePin, OUTPUT);
  pinMode(windowPin, OUTPUT);
  pinMode(relayLightDownPin, OUTPUT);
  pinMode(relayLightUpPin, OUTPUT);
  pinMode(relayTvPin, OUTPUT);
  pinMode(relayBox1, OUTPUT);
  pinMode(relayBox2, OUTPUT);
  pinMode(relayBox3, OUTPUT);
}

void loop() {

}



//Считывает температуру на улице
getStreetTerm() {
  changeRelayBox(0, 0, 0);
  return (125 * analogRead(relayBoxAnalog)) >> 8;   
}

//Считывает температуру в комнате
getRoomTerm() {
  changeRelayBox(0, 0, 1);
  return (125 * analogRead(relayBoxAnalog)) >> 8;   
}

//Считывает значение потенциометра красного цвета
getPotRed() {
  changeRelayBox(1, 0, 0);
  return analogRead(relayBoxAnalog);
}

//Считывает значение потенциометра зелёного цвета
getPotGreen() {
  changeRelayBox(1, 0, 1);
  return analogRead(relayBoxAnalog);
}

//Считывает значение потенциометра синего цвета
getPotBlue() {
  changeRelayBox(1, 1, 0);
  return analogRead(relayBoxAnalog);
}

//Считывает значение потенциометра уровня цвета
getPotLightLevel() {
  changeRelayBox(1, 1, 1);
  return analogRead(relayBoxAnalog);
}

//Подключает нужный датчик
changeRelayBox(int relay1, int relay2, int relay3) {
  digitalWrite(relayBox1, relay1);
  digitalWrite(relayBox2, relay2);
  digitalWrite(relayBox3, relay3);
  delay(50);
}