//k-map expression
#include <WiFi.h>
  #include <WiFiUdp.h>
  #include <ArduinoOTA.h>
  #ifndef STASSID
  #define STASSID "SSID"  // Replace with your network credentials
  #define STAPSK  "PSWD"
  #endif

  const char* ssid = STASSID;
  const char* password = STAPSK;

  void OTAsetup() {
   WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
  delay(5000);
  ESP.restart();
   }
   ArduinoOTA.begin();
  }
  void OTAloop() {
   ArduinoOTA.handle();
  }
 

  int p,q,s;
  int y;
  void setup()
{
    OTAsetup();
    pinMode(13,OUTPUT);
    pinMode(14,INPUT);
    pinMode(15,INPUT);
    pinMode(16,INPUT);
  }
 
  void loop() 
{
    OTAloop();
    delay(10);  // If no custom loop code ensure to have a delay in loop
  p=digitalRead(14);
  q=digitalRead(15);
  s=digitalRead(16);
  y=(p&&!q)||(!q&&!s)||(!p&&q&&s);
  digitalWrite(13,y);
  }
