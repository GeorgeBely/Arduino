#include <VirtualWire.h>

int echo2Pin = 3;
int trig2Pin = 4;
int green2Pin = 5;
int red2Pin = 6;
int echo1Pin = 7;
int trig1Pin = 8;
int green1Pin = 9;
int red1Pin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(trig1Pin, OUTPUT);
  pinMode(echo1Pin, INPUT);  
  pinMode(trig2Pin, OUTPUT);
  pinMode(echo2Pin, INPUT);  
  vw_set_ptt_inverted(true); 
  vw_setup(2000);
}

void loop() {
  int range1 = getRange(trig1Pin, echo1Pin);
  int range2 = getRange(trig2Pin, echo2Pin);

  if (range1 > 10 && range1 < 50) {
    analogWrite(green1Pin, 0);
    analogWrite(red1Pin, 255);  
  } else {
    analogWrite(green1Pin, 255);
    analogWrite(red1Pin, 0);  
  }
  if (range2 > 10 && range2 < 50) {
    analogWrite(green2Pin, 0);
    analogWrite(red2Pin, 255);  
  } else {
    analogWrite(green2Pin, 255);
    analogWrite(red2Pin, 0);  
  }

  String strMsg = "r1:";
  strMsg += range1;
  strMsg += "r2:";
  strMsg += range2;
  sendMessageByRadio(strMsg); 
  Serial.println(strMsg);


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

void sendMessageByRadio(String str) {
  String message = "$";
  message += str;
  message += "$";
  char msg[255];
  message.toCharArray(msg, 255);

  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); 
  delay(200); 
}

