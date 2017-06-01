#include <VirtualWire.h>

#define transmit_pin  12 
#define X_pin A0
#define Y_pin A1
#define BUTTON_PIN 7

String strMsg;

boolean g = false; 
boolean h = false; 
boolean j = false; 
boolean k = false; 
  
void setup() { 
  Serial.begin(9600);
  
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(transmit_pin); 
  vw_setup(2000);       
  
  pinMode (X_pin, INPUT);
  pinMode (Y_pin, INPUT);
  pinMode (BUTTON_PIN, INPUT);
  
  
}

void loop() { 

  int x = analogRead(X_pin); 
  int y = analogRead(Y_pin);
  boolean button = digitalRead(BUTTON_PIN);
    Serial.print(x);
    Serial.println(y);
 
  if (button) {
    strMsg = "";
    strMsg += "FAR";
    sendMessageByRadio(strMsg);
  }
  
  if (x > 530 && g == false){
    g = true;
    strMsg = "";
    strMsg += "forward";
    sendMessageByRadio(strMsg);
  }
 
  if (x > 510 && x < 530 && g == true) {
    strMsg = "";
    strMsg += "stop";
    sendMessageByRadio(strMsg);
    g = false;
  }
  
  if (x < 510 && h == false){
    h = true;
    strMsg = "";
    strMsg += "ago";
    sendMessageByRadio(strMsg);
  }
   
   if (x > 510 && x < 530 && h == true) {
    strMsg = "";
    strMsg += "stop";
    sendMessageByRadio(strMsg);
    h = false;
  }
//   if (a && j == false){
//    j = true;
//    strMsg = "";
//    strMsg += "left";
//    sendMessageByRadio(strMsg);
//  }
 
//  if (a == false && j == true) {
//    strMsg = "";
//    strMsg += "stop2";
//    sendMessageByRadio(strMsg);
//    j = false;
//  }

//   if (d && k == false){
//    k = true;
//    strMsg = "";
//    strMsg += "right";
//    sendMessageByRadio(strMsg);
//  }
 
//  if (d == false && k == true) {
//    strMsg = "";
//    strMsg += "stop2";
//    sendMessageByRadio(strMsg);
//    k = false;
//  }
  

}


void sendMessageByRadio(String str) {
    String message = "$";
    message += str;
    message += "$";
    char msg[255];
    message.toCharArray(msg, 255);
    
    vw_send((uint8_t *) msg, strlen(msg));
    vw_wait_tx(); 
    delay(200);
}

