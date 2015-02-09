int potRedPin = A0;
int potGreenPin = A1;
int potBluePin = A2;

int ledRedPin = 11;
int ledGreenPin = 10;
int ledBluePin = 9;

void setup() {
  pinMode(ledRedPin, INPUT);
  pinMode(ledGreenPin, INPUT);
  pinMode(ledBluePin, INPUT);  
}

void loop() {
  analogWrite(ledRedPin, 255 - analogRead(potRedPin)/4);  
  analogWrite(ledGreenPin, 255 - analogRead(potGreenPin)/4);  
  analogWrite(ledBluePin, 255 - analogRead(potBluePin)/4);  
}
