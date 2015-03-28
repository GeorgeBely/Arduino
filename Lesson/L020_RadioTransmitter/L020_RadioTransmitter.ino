#include <VirtualWire.h>

void setup(void) {
  vw_set_ptt_inverted(true); // Необходимо для DR3100
  vw_setup(2000); // Устанавливаем скорость передачи (бит/с)
}

void loop(void) {
  for (int i = 0; i < 300; i++) {
    String strMsg = "";
    strMsg += i;
    sendMessageByRadio(strMsg); 
  }
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

