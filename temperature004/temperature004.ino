#include "DHT.h"
#define led1 3
#define led2 4
#define led3 5

DHT dht;

void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);
  dht.setup(2); 
}

void loop()
{
  float humidity = dht.getHumidity(); 
  float temperature = dht.getTemperature(); 
  Serial.print("\tHumipity :");Serial.print(humidity);Serial.print("%");
  Serial.print("\tTemperature :");Serial.print(temperature);Serial.print("*C");
  Serial.print("\t");Serial.print(dht.toFahrenheit(temperature));Serial.println("*F");
  delay(2000);
  if(temperature<=30){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
  }
  else if((temperature>30)&&(temperature<=36)){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
  }
  else if((temperature>36)&&(temperature<=41)){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
  }
  else{
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
}
