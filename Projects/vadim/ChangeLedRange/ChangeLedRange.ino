int trigPin = 2;
int echoPin = 3;
int ledPin = 5;


void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int distance = getRange(trigPin, echoPin);
  Serial.print(distance);
  Serial.println("cm");
  
  if (distance < 100 && distance > 20) {
     digitalWrite(ledPin, true);
     delay(60000);    
     digitalWrite(ledPin, false);
  }
  
  delay(100);
}

int getRange(int trig, int echo) {
  digitalWrite(trig, HIGH);
  delayMicroseconds(2000);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);
  int distance = (duration/2) / 29.1; 
  
  return distance;
}
