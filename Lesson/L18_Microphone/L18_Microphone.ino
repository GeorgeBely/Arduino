const int ledPin = 13;   
const int microphonePin = A3;

//Пороговая величина (Хлопок)
const int thresholdValue = 400; 

boolean ledValue = false;

void setup() { 
  pinMode(ledPin, OUTPUT);  
} 

void loop() { 
  //Считываем данные с микро
  int sensorValue = analogRead(microphonePin); 
  
  //Если уровень шума больше порогового значения меняем значение светодиода
  if (sensorValue > thresholdValue) 
    ledValue = !ledValue;
    
  digitalWrite(ledPin, ledValue);
}