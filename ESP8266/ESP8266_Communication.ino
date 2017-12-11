#include <ESP8266WiFi.h>
#include <SPI.h> //Serial Peripheral Interface

// Configuration for static ip address
IPAddress ip(192,168,2,10);
IPAddress dns(172,18,27,65);
IPAddress gateway(192,168,2,1);
IPAddress subnet(255,255,255,0);

//wifi parameter 
const char* ssid="";
const char* passwd="";

void setup() {
  // put your setup code here, to run once:
  // Start Serial
Serial.begin(9600);
delay(10);
// Connect to WiFi
Serial.println("Connecting To");
Serial.println(ssid);

// initialize digital pin LED_BUILTIN as an output.
pinMode(LED_BUILTIN, OUTPUT);

//Configure the static ip address
WiFi.config(ip,gateway,subnet,dns);

WiFi.begin(ssid, passwd);
while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    digitalWrite(LED_BUILTIN, HIGH); 
}
  Serial.println("");
  Serial.println("WiFi connected");
// Print the IP address
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println(WiFi.localIP());
delay(1000);  
Serial.println(WiFi.localIP());
delay(1000);    
}
