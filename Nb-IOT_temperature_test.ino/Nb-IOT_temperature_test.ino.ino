/*
  supported board and hardware competible
  
  Arduino UNO please use software serial on pin8=RX pin9=TX and pin4=RST
  Arduino MEGA please use software serial on pin48=RX pin46=TX and pin4=RST 
  NUCLEO_L476RG please use Hardware serial on pin2=RX pin8=TX and pin4=RST
  NodeMCU-32S please use Hardware serial on RX2=RX TX2=TX and 3V3=IOREF
  
  Pre required install library
         - Altsoftserial 

  Example for post random data to Magellan IoT Platform
  please use payload with json format e.g. {"Temperature":25.5,"Humidity":90.4}
  and {"Location":["13.001","100.44"]} for plot the location on MAP
                      |        |
                  latitude  longitude 

  and {"Lamp":0} or {"Lamp":1"} for show the Lamp status on dashboard
*/
#include "Magellan.h"
#include "DHT.h"
Magellan magel;  
DHT dht;        
char auth[]="15873260-f2f2-11e9-96dd-9fb5d8a71344";         //Token Key you can get from magellan platform

String payload;

void setup() 
{
  Serial.begin(9600);
  magel.begin(auth);           //init Magellan LIB
  dht.setup(A0); 
}

void loop() 
{
  /*
    Example send random temperature and humidity to Magellan IoT platform
  */
  String Location="[19.0275851,99.8980813]";
  String rssi = magel.rssi();
  String Temperature=String(dht.getTemperature());
  String Humidity=String(dht.getHumidity());
  //Serial.print("Temperature : "+Temperature);
  //Serial.println("\tHumidity : "+Humidity);
  //delay(1000);
  
  payload="{\"Temperature\":"+Temperature+",\"Humidity\":"+Humidity+",\"RSSI\":"+rssi+"}";       //please provide payload with json format

  magel.post(payload);                                                         //post payload data to Magellan IoT platform
    
}
