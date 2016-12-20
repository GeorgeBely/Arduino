int tran1 = 7;
int tran2 = 12;
int button = 8;

void setup() {
  pinMode(tran1, OUTPUT);
  pinMode(tran2,OUTPUT);
  pinMode(button,INPUT);
}



void loop() {
  if(digitalRead(button)) {
    digitalWrite(tran2, false);
    digitalWrite(tran1,true);
    delay(20);
    digitalWrite(tran1,false);
    delay(20);
    
  }else{
    digitalWrite(tran1,0);
    digitalWrite(tran2,1); 
    delay(20); 
    digitalWrite(tran2,0);
    delay(20); 
  }  


}



