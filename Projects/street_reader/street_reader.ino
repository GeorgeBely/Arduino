#include <VirtualWire.h>
#include "DHT.h"

#define RADIO_TRANSMITTER_PIN 12

#define DHTPIN 2    // modify to the pin we connected

#define RAIN_PIN A4

#define PHOTO_PIN A5
 
 
DHT dht(DHTPIN, DHT21);


void setup(void) {
  vw_set_ptt_inverted(true); // Необходимо для DR3100
  vw_set_tx_pin(RADIO_TRANSMITTER_PIN);
  vw_setup(2000); // Устанавливаем скорость передачи (бит/с)
  dht.begin();
}

void loop(void) {  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  int r = (100.0 / 1023.0) * (1023 -analogRead(RAIN_PIN));
  int p = (100.0 / 1023.0) * (1023 -analogRead(PHOTO_PIN));
 
 /* 
  String str = "Rain: ";
  str += r;
  str += "%\ ";
  str += "Photo: ";
  str += p;
  str += "%\ ";
  str += "Humidity: "; 
  str += (int) h;
  str += " %\ ";
  str += "Temperature: "; 
  str += (int) t;
  str += " *C";
  */
  String str = "r";
  str += r;
  str += "|p";
  str += p;
  str += "|h";
  str += (int) h;
  str += "|t";
  str += (int) t;
 
  sendMessageByRadio(str); 
   
  delay(1000);
}



void sendMessageByRadio(String str) {
  String message = "$";
  message += str;
  message += "$";
  char msg[255];
  message.toCharArray(msg, 255);
  
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx(); // Ждем пока передача будет окончена 
  delay(200); 
}

