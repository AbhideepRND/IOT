#include <ESP8266WiFi.h>
#include <SPI.h> //Serial Peripheral Interface
#include <ESP8266WebServer.h>

// ESP Servere will read the data from 8081 port
ESP8266WebServer server(8081);

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
   // digitalWrite(LED_BUILTIN, HIGH); 
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  server.on("/other", []() {   //Define the handling function for the path
    server.send(200, "text / plain", "Other URL");
  });
 
  //Associate the handler function to the path
  server.on("/signal", handleSignal);   
  //Start the server
  server.begin();                          
  Serial.println("Server listening");

  pinMode(14,OUTPUT);
 // digitalWrite(5,LOW);
  
  pinMode(12,OUTPUT);
  //digitalWrite(6,LOW);
  
  pinMode(13,OUTPUT);
 // digitalWrite(7,LOW);
  
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop(){
  server.handleClient();
}

void handleSignal(){
    String message = "Number of args received:";
      message += server.args();            //Get number of parameters
      message += "\n";                            //Add a new line
    int pin = server.arg(0).toInt();
    int opr = server.arg(1).toInt();
    
    if(opr == 1){
     digitalWrite(pin,HIGH);
    } else{
    digitalWrite(pin,LOW);
    }
    
  
      /*for (int i = 0; i < server.args(); i++) {
            message += "Arg " + (String)i + " –> ";   //Include the current iteration value
            message += server.argName(i) + ": ";     //Get the name of the parameter
            message += server.arg(i) + "\n";              //Get the value of the parameter
      
      } */  
    
  
    Serial.println("Signal Found");
    Serial.println(message);
    server.send(200, "text/plain", "Hello world");
}

