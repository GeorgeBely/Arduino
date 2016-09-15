int trigPin = 3;
int echoPin = 2;

int ledR = 8;
int ledG = 12;

void setup() {
  Serial.begin(9600);
  pinMode (trigPin, OUTPUT);
  pinMode (echoPin, INPUT);
  
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
}

void loop () {  
  int distance = getRange(trigPin, echoPin);
  Serial.print(distance);
  Serial.println("cm");
  
  if (distance > 150) {
    analogWrite(ledR, 0);
    analogWrite(ledG, 255); 
    delay(500); 
  } else {
    analogWrite(ledR, 255);
    analogWrite(ledG, 0);  
    delay(500);
  }  
}

int getRange(int trig, int echo) {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2000);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  int distance = (duration/2) / 29.1; 
  
  return distance;
}
