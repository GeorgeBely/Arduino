int in = 7;
int out = 8;
int left = 12;
int right = 10;

int buttonIn = 2;
int buttonOut = 5;
int buttonLeft = 3;
int buttonRight = 4;

void setup() {
  pinMode(buttonIn, INPUT);
  pinMode(buttonOut, INPUT);
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(in, OUTPUT);  
  pinMode(out, OUTPUT); 
  pinMode(left, OUTPUT);  
  pinMode(right, OUTPUT); 
}

void loop() {  
  digitalWrite(in, digitalRead(buttonIn));
  digitalWrite(out, digitalRead(buttonOut));  
  digitalWrite(left, digitalRead(buttonLeft));
  digitalWrite(right, digitalRead(buttonRight));
}
