#include <MQ135.h>

#define R0 1200
#define PARA 116.6020682 // параметры для вычисления CO2
#define PARB 2.769034857
 
void setup(){
  Serial.begin(9600); 
  
   Serial.print("Calibrating ");
  //for(int i = 0; i < 40; i++){
 //   Serial.print(".");
 //   delay(1000); 
//  }   
}

void loop(){
  int MQ135val = analogRead(A0);
  Serial.println(MQ135val);
  float Resistance = ((1023. / (float)MQ135val) * 5. - 1.) * RLOAD; //расчет текущего сопротивления
  double CO2 = PARA * pow((Resistance / R0), -PARB); //пересчет в ppm
  
  Serial.print("CO2: ");
  Serial.print(CO2);
  Serial.println("ppm");
  
  
  delay (1000);
  
  
}
