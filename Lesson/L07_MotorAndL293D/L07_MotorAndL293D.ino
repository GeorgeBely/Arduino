int in = 7;
int out = 8;
int left = 12;
int right = 10;

void setup() {
  pinMode(in, OUTPUT);  
  pinMode(out, OUTPUT); 
  pinMode(left, OUTPUT);  
  pinMode(right, OUTPUT); 
}

void loop() {  
  digitalWrite(in, true);
  digitalWrite(out, false);  
  digitalWrite(left, true);
  digitalWrite(right, false);
  delay(1000);
}
