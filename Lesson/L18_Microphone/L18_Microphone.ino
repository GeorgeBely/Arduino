const int ledPin = 13;   
const int microphonePin = A3;

//Пороговая величина (Хлопок)
const int thresholdValue = 400; 

void setup() { 
  pinMode(ledPin, OUTPUT);  
} 

void loop() { 
  //Считываем данные с микро
  int sensorValue = analogRead(microphonePin); 
  
  //Если уровень шума больше порогового значения включаем светодиод
  if (sensorValue > thresholdValue) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
  }
}