int led1 = 3;
int led2 = 13;

int led2time = 0;
int value = 0;
boolean led2cvet = 0;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);

}




void loop() {
 if(led2cvet && led2time < 1000) {
    digitalWrite(led2,1);
    delay(50);
    digitalWrite(led2,0);
    delay(50);
    led2time += 100;
 } else {  
   if(value == 255) {
       delay(1000);
       value = 0;
       led2cvet = !led2cvet;
       led2time = 0;
    }
    value++;
    analogWrite(led1,value);
    delay(20);
 }












}

