//Дальномеры для определения количества людей в комнате
int range1TrigPin = 13;
int range1EchoPin = 12;
int range2TrigPin = 8;
int range2EchoPin = 7;

int lightRedPin = 11;
int lightGreenPin = 10;
int lightBluePin = 9;

     
//1. Табло с отображением времени
//2. Табло с отображением комнатной температуры
//3. Табло с отображением уличной температуры
//4. Отключение нижниго и верхнего света
int digitalBoxPin1 = 5
int digitalBoxPin2 = 6

int relayDigitalBox1 = 3
int relayDigitalBox2 = 4
          
//1. Термометр уличный
//2. Термометр комнатный
//3. Фоторезистор
//4. Датчик дождя/снега
//5. Потенциометр основного света (красный)
//6. Потенциометр основного света (зелёный)
//7. Потенциометр основного света (синий)
//8. Потенциометр уровня основного света
int analogBoxPin = A0;                  
//Бокс реле для подключения к аналоговому выходу 0 
//несколькох датчиков.
int relayAnalogBox1 = 0;
int relayAnalogBox2 = 1;
int relayAnalogBox3 = 2

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
  pinMode(relayAnalogBox1, OUTPUT);
  pinMode(relayAnalogBox2, OUTPUT);
  pinMode(relayAnalogBox3, OUTPUT);
}

void loop() {

}



//Считывает температуру на улице
getStreetTerm() {
  changeRelayAnalogBox(0, 0, 0);
  return (125 * analogRead(relayBoxAnalog)) >> 8;
}

//Считывает температуру в комнате
getRoomTerm() {
  changeRelayAnalogBox(0, 0, 1);
  return (125 * analogRead(relayBoxAnalog)) >> 8;
}

//Считывает значение потенциометра красного цвета
getPotRed() {
  changeRelayAnalogBox(1, 0, 0);
  return analogRead(relayBoxAnalog);
}

//Считывает значение потенциометра зелёного цвета
getPotGreen() {
  changeRelayAnalogBox(1, 0, 1);
  return analogRead(relayBoxAnalog);
}

//Считывает значение потенциометра синего цвета
getPotBlue() {
  changeRelayAnalogBox(1, 1, 0);
  return analogRead(relayBoxAnalog);
}

//Считывает значение потенциометра уровня цвета
getPotLightLevel() {
  changeRelayAnalogBox(1, 1, 1);
  return analogRead(relayBoxAnalog);
}

//Подключает нужный датчик
changeRelayAnalogBox(int relay1, int relay2, int relay3) {
  digitalWrite(relayAnalogBox1, relay1);
  digitalWrite(relayAnalogBox2, relay2);
  digitalWrite(relayAnalogBox3, relay3);
  delay(50);
}

//Используем светодиодную панель отображения времени
useTimePanel() {
  changeRelayDigitalBox(0, 0);
}

//Используем светодиодную панель отображения уличной температуры
useStreetTermPanel() {        
  changeRelayDigitalBox(0, 1);

}
                                         
//Используем светодиодную панель отображения комнатной температуры
useRoomTermPanel() {        
  changeRelayDigitalBox(1, 0);

}

//Используем реле для отключения света
useOffLight() {
  changeRelayDigitalBox(1, 1);

}


//Подключает нужное устройство
changeRelayDigitalBox(int relay1, int relay2) {
  digitalWrite(relayDigitalBox1, relay1);
  digitalWrite(relayDigitalBox2, relay2);
  delay(50);
}