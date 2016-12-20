#include <SoftwareSerial.h>

//заводим Serial-соединение с GPRS-Shield на 7 и 8 цифровых входах
SoftwareSerial gprsSerial(7, 8);


void setup() {
  // GPRS Shield общается по умолчанию на скорости 19200 бод
  gprsSerial.begin(19200);
  
  // Настраиваем приём сообщений с других устройств
  // Между командами даём время на их обработку
  gprsSerial.print("AT+CMGF=1\r");
  delay(300);
  gprsSerial.print("AT+IFC=1, 1\r");
  delay(300);
  gprsSerial.print("AT+CPBS=\"SM\"\r");
  delay(300);
  gprsSerial.print("AT+CNMI=1,2,2,1,0\r");
  delay(500);
  
  Serial.begin(9600);
}
    
void loop() {
  monitoringGSM();
}


//в строке curStr будем хранить текущую строку, 
//которую передает нам плата
String currStr = ""; 

// Переменная принимает значение True, 
// если текущая строка является сообщением
boolean isStringMessage = false;

/*
 * Функция опрашивает GSM модуль на наличие входящего звонка или СМС.
 * При их наличии реагирует должным образом.
 * Для ответа используется функция answerToCall()
 * Для прочтения СМС используется функция readSMS()
 */
void monitoringGSM() {
  touch();
  
  if (!gprsSerial.available())
    return;

  // Считываем очередной символ с платы
  char currSymb = gprsSerial.read();    
  

  if ('\r' == currSymb) {
    if (currStr.startsWith("+CMT")) {
      //если текущая строка начинается с "+CMT",
      //то следующая строка является сообщением
      isStringMessage = true;    
    } else if (isStringMessage) {
      readSMS(currStr);
      isStringMessage = false;
    } else if (currStr == "RING") {
      // Получен символ перевода строки, это значит, что текущее
      // сообщение от платы завершено и мы можем на него отреагировать.
      // Если текущая строка - это RING, то значит, нам кто-то звонит
      answerToCall();
    }
    currStr = "";
  } else if (currSymb != '\n') {
    // Дополняем текущую команду новым сиволом
    // При этом игнорируем второй символ в последовательности переноса
    // строки: \r\n
    currStr += String(currSymb);
  }
  
}

/*
 * Ответ на входящий звонок
 */
void answerToCall() {
  //кокетничаем 3 секунды, чтобы дать услышать звонящему гудок
  delay(3000);
  //посылаем команду на поднятие трубки
  gprsSerial.println("ATA");
}

/*
 * Cразу после вызова функции начинаем звонить по заданному номеру
 *
 * @param number - номер телефона в формате "+79XXXXXXXXX"
 */
void callTo(String number) {
  gprsSerial.print("ATD + ");
  gprsSerial.print(number);
  gprsSerial.println(";");
}

/*
 * Разбираем СМС. 
 *
 * @param message - текст сообщения
 */
void readSMS(String message) {
  Serial.println(message);
  sendSMS(message, "+79507775731");
}

/*
 * Отправляем СМС сообщение на указаный номер.
 *
 * @param message - текст сообщения
 * @param number - номер телефона в формате "+79XXXXXXXXX"
 */
void sendSMS(String message, String number) {
  // Устанавливает текстовый режим для SMS-сообщений
  gprsSerial.print("AT+CMGF=1\r");
  delay(100); // даём время на усваивание команды
  
  // Устанавливаем адресата: телефонный номер в международном формате
  gprsSerial.print("AT + CMGS = \"");
  gprsSerial.print(number);
  gprsSerial.println("\"");
  delay(100);
  
  // Пишем текст сообщения
  gprsSerial.println(message);
  delay(1000);
  
  // Отправляем Ctrl+Z, обозначая, что сообщение готово
  gprsSerial.println((char)26);
} 

int updateTime = 0;
/*
 * Функция провоцирует поддержание коммуникации с платой даже если
 * та была перезагружена без перезагрузки Arduino
 */
void touch() {
  if (millis() >= updateTime) {
    gprsSerial.println("AT");
    updateTime += 5000;
  }
}


