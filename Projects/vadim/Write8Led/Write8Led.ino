int zero[] = {2, 3, 4, 5, 7, 8, 9};
int one[] = {3, 4, 5};
int two[] = {2, 3, 4, 6, 8, 9};
int three[] = {2, 3, 4, 5, 6, 8};
int four[] = {3, 4, 5, 6, 7};
int five[] = {2, 4, 5, 6, 7, 8};
int six[] = {2, 4, 5, 6, 7, 8, 9};
int seven[] = {2, 3, 4, 5};
int eight[] = {2, 3, 4, 5, 6, 7, 8, 9};
int nine[] = {2, 3, 4, 5, 6, 7, 8};

int count = 0;

int echoPin = 11;
int trigPin = 10;

void setup() {
  Serial.begin(9600);
  for(int i = 2; i < 10; i++) {
    pinMode(i, OUTPUT);
  }   
  
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  
  write8Led(0);
}

void loop() {  
  int distance = getRange(trigPin, echoPin);
  
  Serial.print (distance);
  Serial.println("cm");
  if (distance < 100) {
    count++;
    write8Led(count);
  }  
  
  delay(2000);
}

int getRange(int trig, int echo) {
  digitalWrite(trig, HIGH);
  delayMicroseconds(2000);
  digitalWrite(trig, LOW);
  int duration = pulseIn(echo, HIGH);
  int distance = (duration/2) / 29.1; 
  
  return distance;
}


void write8Led(int value) {  
  if (value == 0)
    writeZero();
  else if (value == 1)
    writeOne();  
  else if (value == 2)
    writeTwo();  
  else if (value == 3)
    writeThree();
  else if (value == 4)
    writeFour(); 
  else if (value == 5)
    writeFive(); 
  else if (value == 6)
    writeSix();  
  else if (value == 7)
    writeSeven();
  else if (value == 8)
    writeEight();
  else if (value == 9)
    writeNine(); 
}

void writeZero() { write8Led(7, zero); }
void writeOne() { write8Led(3, one); }
void writeTwo() { write8Led(6, two); }
void writeThree() { write8Led(6, three); }
void writeFour() { write8Led(5, four); }
void writeFive() { write8Led(6, five); }
void writeSix() { write8Led(7, six); }
void writeSeven() { write8Led(4, seven); }
void writeEight() { write8Led(8, eight); }
void writeNine() { write8Led(7, nine); }

void removeAll8Led() {
  for(int i = 2; i < 10; i++) {
    digitalWrite(i, true);  
  }  
}

/**
 *
 *
 * @param length
 * @param mass
 */
void write8Led(int length, int mass[]) {
    removeAll8Led();
    for(int i = 0; i < length; i++) {
        digitalWrite(mass[i], false);
    }
}

