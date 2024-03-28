#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define ADCPin A0
int ADCValue;
char auth[] = "eRu44_yC3a4Hp0iQReVDAhs6RySawNY5";
char ssid[] = "Peeranat";
char pass[] = "Peeranat";
void setup() 
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass,"elec.cmtc.ac.th",8080);
}
void loop() 
{
  Blynk.run();
  ADCValue = analogRead(ADCPin);
  Serial.print("ADC =  ");
  Serial.println(ADCValue);
}
