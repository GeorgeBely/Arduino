    #include <SoftwareSerial.h>
     
    //заводим Serial-соединение с GPRS-Shield на 7 и 8 цифровых входах
    SoftwareSerial gprsSerial(7, 8);
     
    void setup()
    {
        // GPRS Shield общается по умолчанию на скорости 19200 бод
        gprsSerial.begin(19200);
    }
     
    //в строке curStr будем хранить текущую строку, которую передает нам плата
    String currStr = ""; 
    int updateTime = 0;
     
    void loop()
    {
        touch();
     
        if (!gprsSerial.available())
            return;
     
        // Считываем очередной символ с платы
        char currSymb = gprsSerial.read();    
     
        if ('\r' == currSymb) { 
            // Получен символ перевода строки, это значит, что текущее
            // сообщение от платы завершено и мы можем на него отреагировать.
            // Если текущая строка - это RING, то значит, нам кто-то звонит
            if (!currStr.compareTo("RING")) {
                //кокетничаем 3 секунды, чтобы дать услышать звонящему гудок
                delay(3000);
                //посылаем команду на поднятие трубки
                gprsSerial.println("ATA");
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
     * Функция провоцирует поддержание коммуникации с платой даже если
     * та была перезагружена без перезагрузки Arduino
     */
    void touch()
    {
        if (millis() >= updateTime) {
            gprsSerial.println("AT");
            updateTime += 5000;
        }  
    }


