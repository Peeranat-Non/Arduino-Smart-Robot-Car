#define PWM_ML D2
#define in1_ML D4
#define in2_ML D7
#define in1_MR D8
#define in2_MR D9
#define PWM_MR D3
#define IRsensorL D5
#define IRsensorR D6
int LsensorValue, RsensorValue;
int Speed = 300;
#include <ESP8266WiFi.h>
void setup()
{
pinMode (PWM_ML, OUTPUT);
pinMode (in1_ML, OUTPUT);
pinMode (in2_ML, OUTPUT); 
pinMode (PWM_MR, OUTPUT);
pinMode (in1_MR, OUTPUT); 
pinMode (in2_MR, OUTPUT);
pinMode (IRsensorL, INPUT);
pinMode (IRsensorR, INPUT);
}
void loop()
{
 LsensorValue = digitalRead (IRsensorL);
 RsensorValue = digitalRead (IRsensorR);
 if (LsensorValue ==1 &&RsensorValue==0)
  {
  TurnRight();
  } 
else if (LsensorValue==0 &&RsensorValue==1)
  {
  TurnLeft();
  }
else if (LsensorValue==0 &&RsensorValue==0)
  {
  ForWard();
  }
else
  {
    
  Stop();
  }
}
void ForWard()
{
//สั่งให้มอเดอรซ้าย เดินหน้า
digitalWrite (in1_ML, HIGH);
digitalWrite (in2_ML, LOW);
analogWrite (PWM_ML, Speed);
//สั่งใหมอเดอรขวา เดินหน้า
digitalWrite (in1_MR, HIGH);
digitalWrite(in2_MR, LOW);
analogWrite (PWM_MR, Speed);
}
void TurnLeft()
{
//สั่งให้มอเดอร์ซ้าย ถอยหลัง
digitalWrite (in1_ML, LOW);
digitalWrite (in2_ML, HIGH);
analogWrite (PWM_ML, Speed);
//สั่งให้มอเดอรขวา เดินหน้า
digitalWrite (in1_MR, HIGH);
digitalWrite(in2_MR, LOW);
analogWrite (PWM_MR, Speed);
}
void TurnRight ()
{
//สั่งให้มอเตอรชาย เดินหน้า
digitalWrite(in1_ML, HIGH); 
digitalWrite(in2_ML, LOW);
analogWrite (PWM_ML, Speed);
//สั่งให้มอเตอรขวา ถอยหลัง
digitalWrite (in1_MR, LOW);
digitalWrite (in2_MR, HIGH);
analogWrite (PWM_MR, Speed);
}
void Stop()
{
//สั่งให้มอเตอรชาย หยุด
digitalWrite(in1_ML, LOW);
digitalWrite(in2_ML, LOW);
analogWrite (PWM_ML, 0);
//สั่งให้มอเตอรขวา หยุด
digitalWrite(in1_MR,LOW);
digitalWrite (in2_MR, LOW);
analogWrite (PWM_MR, 0);
}