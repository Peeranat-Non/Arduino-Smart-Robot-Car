#include <Servo.h>
Servo myservo;
int degree;
int readdegree;
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "5vHlqOPHKI_VT45p6yW0Y4-JERxT3g08";
char ssid[] = "kui";
char pass[] = "eexi2234556";
void setup() 
{
  myservo.attach(D7);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,"elec.cmtc.ac.th",8080);
}


void loop() 
{
  Blynk.run();
  readdegree = myservo.read();
  Blynk.virtualWrite(V0,readdegree);
}
BLYNK_WRITE(V1)
{
  degree = param.asInt();
  myservo.write(degree);
}