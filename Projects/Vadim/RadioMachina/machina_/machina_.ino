#include <VirtualWire.h>

#define receiver_pin 12
#define I1 2
#define I2 3
#define I3 4
#define I4 5
#define LED_STOP 6
#define LED_FAR 7

boolean FAR = false;

void setup() 
{ 
  Serial.begin(9600);
  Serial.println("MX-RM-5V is ready"); 
  vw_set_rx_pin(receiver_pin);
  vw_set_ptt_inverted(true); 
  vw_setup(2000);
  vw_rx_start();
  
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
  pinMode(LED_STOP, OUTPUT );
  pinMode(LED_FAR, OUTPUT ) ;
} 
void loop() {    
  String result = readMessageByRadio();
  Serial.println(result);
  if (result == "forward") {
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
  }

   if (result == "ago") {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
    digitalWrite(LED_STOP, HIGH);
   }
  
  if (result == "left") {
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
   }

   if (result == "right") {
    digitalWrite(I4, HIGH);
    digitalWrite(I3, LOW);
   }

  if (result == "stop"){
      digitalWrite(I1, LOW);
      digitalWrite(I2, LOW);
      digitalWrite(LED_STOP, LOW);
  }

  if (result == "stop2"){
      digitalWrite(I3, LOW);
      digitalWrite(I4, LOW);
  }

  if (result == "FAR") {
    FAR = !FAR;
  }
  
  digitalWrite(LED_FAR, FAR);
  delay(500);
}


String readMessageByRadio() {
    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) {
        if (buf[0] != '$') {
            return "";
        }
    
        int i = 1;
        String result = "";
        while (buf[i] != '$') {
            char ch = buf[i];
            result += ch;
            i++;
        }
        return result;
    }
    return "";
}
