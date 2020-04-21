#include "DHT.h"


DHT dht;

void setup()
{
  Serial.begin(9600);
  dht.setup(A0); 
}

void loop()
{
  float humidity = dht.getHumidity(); 
  float temperature = dht.getTemperature(); 
  Serial.print("\tHumipity :");Serial.print(humidity);
  Serial.print("\tTemperature :");Serial.print(temperature);Serial.print("*C");
  Serial.print("\t");Serial.print(dht.toFahrenheit(temperature));Serial.println("*F");
  delay(1000);
}
