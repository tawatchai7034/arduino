#include "DHT.h"

#define DHTPIN A0
#define DHTTYPE DHT22
#define led1 3
#define led2 4
#define led3 5
DHT dht(DHTPIN, DHTTYPE);
const float baselineTemmp = 20.0;

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);
  for(int pinNumber = 2; pinNumber<5;pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber,LOW);
  }
 dht.begin();
}

void loop() {
  int sensorVal = analogRead(DHTPIN);
  Serial.print("\tsensor Value : "); Serial.print(sensorVal);
  delay(500);

  float voltage=(sensorVal/1024.0)*5.0;
  Serial.print("\tVolts : "); Serial.print(voltage);
  delay(500);
  
  float temperature= (voltage-.5)*100;
  Serial.print("\tdegrees C: "); Serial.println(temperature);
  delay(500);
  
    if(temperature<baselineTemmp){
       digitalWrite(led1,HIGH);
       digitalWrite(led2,LOW);
       digitalWrite(led3,LOW);
      }
    else if(temperature >= baselineTemmp && temperature<baselineTemmp+5){   
       digitalWrite(led1,LOW);
       digitalWrite(led2,HIGH);
       digitalWrite(led3,LOW);
      }
    else if(temperature>baselineTemmp+10){   
       digitalWrite(led1,LOW);
       digitalWrite(led2,LOW);
       digitalWrite(led3,HIGH);
     }
}
