#include <ESP8266WiFi.h>
#define LINE_TOKEN "vKdJzJyltgOXDC68pgKmgOSw5Xo7xevGdktbxRVcc1r" //Line token
const char* ssid2 = "Peeranat"; // your wifi SSID name
const char* password = "peeranat43109" ;// wifi pasword
 
void setup() {
  delay(100);
  WiFi.disconnect();
  delay(10);
  WiFi.begin(ssid2, password);
    Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");

 }

void loop() {
  String message = "Test";
  WiFiClientSecure client;
  if (client.connect("notify-api.line.me", 443)) {
    Serial.println("connection failed");
    return;   
  }
  String req = "";
  req += "POST /api/notify HTTP/1.1\r\n";
  req += "Host: notify-api.line.me\r\n";
  req += "Authorization: Bearer " + String(LINE_TOKEN) + "\r\n";
  req += "Cache-Control: no-cache\r\n";
  req += "User-Agent: ESP8266\r\n";
  req += "Content-Type: application/x-www-form-urlencoded\r\n";
  req += "Content-Length: " + String(String("message=" + message).length()) + "\r\n";
  req += "\r\n";
  req += "message=" + message;
  client.print(req);

  delay(10);

  // Serial.println("-------------");
  while(client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
    //Serial.println(line);
  }
  // Serial.println("-------------");
  delay(1000);
}
