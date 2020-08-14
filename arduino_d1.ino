#include <ESP8266WiFi.h>

//#include <HCSR04.h>

//UltraSonicDistanceSensor distanceSensor(D4, D3); //trig,echo

const char* ssid = "tester";
const char* password = "abcd1234";
const char* host = "maker.ifttt.com";

#define resetPin D8

byte token=0;

void setup() 
{
  Serial.begin(115200);
  Serial.println("Email from Node Mcu");
  delay(100);

  pinMode(resetPin,OUTPUT);
  digitalWrite(resetPin,HIGH);
  
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());  
}
void loop() 
{       
  WiFiClient client; 
  const int httpPort = 80;  
  
  if (!client.connect(host, httpPort)) 
  {  
    Serial.println("connection failed");  
    return;
  } 
  
  //int distance = distanceSensor.measureDistanceCm();
  
  if(token==0)
  {
//    digitalWrite(resetPin,LOW);
//    delay(1000);
//    digitalWrite(resetPin,HIGH);
    
    String url = "/trigger/obstacle/with/key/bbMDd_S50GGi5HagtoS61IxpPr-9LK39QtqBvvQXsl3"; 
    Serial.print("Requesting URL: ");
    Serial.println(url);
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + 
    "Host: " + host + "\r\n" +   
    "Connection: close\r\n\r\n");   
    
    token=1;
  }
}
