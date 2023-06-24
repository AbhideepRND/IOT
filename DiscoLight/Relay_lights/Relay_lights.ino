#include <SPI.h> //Serial Peripheral Interface

const int pin[10] = {3,1,16,5,4,14,12,13,15};
void setup() {
  // put your setup code here, to run once:
  // Start Serial
    Serial.begin(9600);
    delay(10);
  
  for(int i=0; i<10; i++){
    pinMode(pin[i],OUTPUT);
  }
  
}

void loop(){

    single_light();
  

}

void single_light(){

   for(int i=0; i<10; i++){
      digitalWrite(pin[i],HIGH);
      delay(2);
    }

    delay(4);

    for(int i=0; i<10; i++){
      digitalWrite(pin[i],LOW);
      delay(2);
    }
  
}
