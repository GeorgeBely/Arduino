int led=10;
int ddd=5;


void setup() {
pinMode(ddd,INPUT); 
pinMode(led,OUTPUT);

}

void loop() {
int vadim = analogRead(ddd);
analogWrite(led,vadim/4);








}
