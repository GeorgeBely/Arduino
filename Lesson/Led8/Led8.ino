//set digital IO pin for every segment.
int a=7;//set #7 connect a segment.
int b=6;// set #6 connect b segment.
int c=5;// set #5 connect c segment.
int d=11;// set #11 connect d segment.
int e=10;// set #10 connect e segment.
int f=8;// set #8 connect f segment.
int g=9;// set #9 connect g segment.
int dp=4;// set #4 connect dp segment.
void digital_1(void) //display number ¡°1¡±
{
unsigned char j;
digitalWrite(c,HIGH);//gives #5 pin high level, lighten c segment digitalWrite(b,HIGH);// lighten b segment
for(j=7;j<=11;j++)//turn off the rest segments
digitalWrite(j,LOW);
digitalWrite(dp,LOW);//turn off decimal point DP segment
}
void digital_2(void) // display number ¡°2¡±

{
unsigned char j;
digitalWrite(b,HIGH);
digitalWrite(a,HIGH);
for(j=9;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
digitalWrite(c,LOW);
digitalWrite(f,LOW);
}
void digital_3(void) // display number ¡°3¡±
{
unsigned char j;
digitalWrite(g,HIGH);
digitalWrite(d,HIGH);
for(j=5;j<=7;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
digitalWrite(f,LOW);
digitalWrite(e,LOW);
}
void digital_4(void) // display number ¡°4¡±

{
digitalWrite(c,HIGH);
digitalWrite(b,HIGH);
digitalWrite(f,HIGH);
digitalWrite(g,HIGH);
digitalWrite(dp,LOW);
digitalWrite(a,LOW);
digitalWrite(e,LOW);
digitalWrite(d,LOW);
}
void digital_5(void) // display number ¡°5¡±
{
unsigned char j;
for(j=7;j<=9;j++)
digitalWrite(j,HIGH);
digitalWrite(c,HIGH);
digitalWrite(d,HIGH);
digitalWrite(dp,LOW);
digitalWrite(b,LOW);
digitalWrite(e,LOW);
}
void digital_6(void) // display number ¡°6¡±
{
unsigned char j;
for(j=7;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(c,HIGH);
digitalWrite(dp,LOW);
digitalWrite(b,LOW);
}
void digital_7(void) // display number ¡°7¡±
{
unsigned char j;
for(j=5;j<=7;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
for(j=8;j<=11;j++)
digitalWrite(j,LOW);
}
void digital_8(void) // display number ¡°8¡±
{
unsigned char j;
for(j=5;j<=11;j++)
digitalWrite(j,HIGH);
digitalWrite(dp,LOW);
}
void setup()
{
int i;//define variable
for(i=4;i<=11;i++)
pinMode(i,OUTPUT);//set #4-11 pin in output mode
}
void loop()
{
while(1)
{
digital_1();//display number ¡°1¡±
delay(2000);//delay 2s
digital_2();//display number ¡°2¡±
delay(1000); //delay 1s
digital_3();//display number ¡°3¡±
delay(1000); //delay 1s
digital_4();//display number ¡°4¡±
delay(1000); //delay 1s
digital_5();//display number ¡°5¡±
delay(1000); //delay 1s
digital_6();//display number ¡°6¡±
delay(1000); //\delay 1s
digital_7();//display number ¡°7¡±
delay(1000); //delay 1s
digital_8();//display number ¡°1¡±
delay(1000); //delay 1s
}
}
