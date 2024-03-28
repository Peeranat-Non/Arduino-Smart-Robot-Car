#include <Servo.h>
Servo myarm;
#define PWM_ML D2
#define in1_ML D4
#define in2_ML 10
#define in1_MR D8
#define in2_MR D9
#define PWM_MR D3
#define IRsensorL D5
#define IRsensorR D6
int LsensorValue, RsensorValue;
int Speed = 700;
#include <Ultrasonic.h>
Ultrasonic ultrasonic(D0, D1);
int distanceCM;
void setup()
{
  myarm.attach (D7);
  pinMode (PWM_ML, OUTPUT);
  pinMode (in1_ML, OUTPUT);
  pinMode (in2_ML, OUTPUT);
  pinMode (PWM_MR, OUTPUT);
  pinMode (in1_MR, OUTPUT); 
  pinMode (in2_MR, OUTPUT);
  pinMode (IRsensorL, INPUT);
  pinMode (IRsensorR, INPUT);
  myarm.write (10);
}
void loop()
{
  distanceCM = ultrasonic.read (CM);
  if (distanceCM <= 5)
  {
    Stop();
    myarm.write(160);
    delay(700);
    myarm.write(10);
  }
  else
  {
    Follow();
  }
}
void Follow()
{
  LsensorValue = digitalRead (IRsensorL);
  RsensorValue = digitalRead (IRsensorR);
  if (LsensorValue == 0 && RsensorValue == 1)
  {
    TurnLeft();
  }
  else if (LsensorValue == 1 && RsensorValue == 0)
  {
    TurnRight();
  }
  else if (LsensorValue == 0 && RsensorValue == 0)
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
  
  digitalWrite (in1_ML, HIGH);
  digitalWrite (in2_ML, LOW);
  analogWrite  (PWM_ML, Speed);

  digitalWrite (in1_MR, HIGH);
  digitalWrite (in2_MR, LOW);
  analogWrite  (PWM_MR, Speed);
}
void TurnLeft()
{
  
  digitalWrite (in1_ML, LOW);
  digitalWrite (in2_ML, HIGH);
  analogWrite  (PWM_ML, Speed);

  digitalWrite (in1_MR, HIGH);
  digitalWrite (in2_MR, LOW);
  analogWrite  (PWM_MR, Speed);
}
void TurnRight()
{
  
  digitalWrite (in1_ML, HIGH);
  digitalWrite (in2_ML, LOW);
  analogWrite  (PWM_ML, Speed);

  digitalWrite (in1_MR, LOW);
  digitalWrite (in2_MR, HIGH);
  analogWrite  (PWM_MR, Speed);
}
void Stop()
{
  
  digitalWrite (in1_ML, LOW);
  digitalWrite (in2_ML, LOW);
  analogWrite  (PWM_ML, 0);

  digitalWrite (in1_MR, LOW);
  digitalWrite (in2_MR, LOW);
  analogWrite  (PWM_MR, 0);
}
void BackWard()
{
  
  digitalWrite (in1_ML, LOW);
  digitalWrite (in2_ML, HIGH);
  analogWrite  (PWM_ML, Speed);

  digitalWrite (in1_MR, LOW);
  digitalWrite (in2_MR, HIGH);
  analogWrite  (PWM_MR, Speed);
}