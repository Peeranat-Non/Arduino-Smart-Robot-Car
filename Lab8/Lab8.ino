#include <Ultrasonic.h>
Ultrasonic ultrasonic (D0,D1);
int distanceCM;
int distanceINC;
#define PWM_ML D2
#define in1_ML D4
#define in2_ML D7
#define in1_MR D8
#define in2_MR D9
#define PWM_MR D3
int Speed = 850 ;
void setup() {
    pinMode(PWM_ML , OUTPUT);
    pinMode(in1_ML , OUTPUT);
    pinMode(in2_ML , OUTPUT);
    pinMode(PWM_MR , OUTPUT);
    pinMode(in1_MR , OUTPUT);
    pinMode(in2_MR , OUTPUT);

}
void loop() 
{
  distanceCM = ultrasonic.read(CM);
  if (distanceCM <= 5)
  {
    Stop();
  }
  else
  {
    ForWard();
  }
}
void ForWard()
{
  //สั้งให้มอเตอร์ซ้าย เดินหน้า
  digitalWrite(in1_ML , HIGH);
  digitalWrite(in2_ML , LOW);
  analogWrite(PWM_ML , Speed);
  //สั่งให้มอเตอร์ขวา เดินหน้า
  digitalWrite(in1_MR , HIGH);
  digitalWrite(in2_MR , LOW);
  analogWrite(PWM_MR , Speed);
}
void Stop()
{
  //สั่งให้มอเตอร์ซ้าย หยุด
  digitalWrite(in1_ML , LOW);
  digitalWrite(in2_ML , LOW);
  analogWrite(PWM_ML , 0);
  //สั่งให้มอเตอร์ขวา หยุด
  digitalWrite(in1_MR , LOW);
  digitalWrite(in2_MR , LOW);
  analogWrite(PWM_MR , 0);
}