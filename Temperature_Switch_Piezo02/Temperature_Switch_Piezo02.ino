#include "DHT.h"
#define led1 4
#define led2 5
#define led3 6
#define button 2
#define button00 3

DHT dht;

boolean state = LOW;
boolean state00 = LOW;
int buttonState;
int buttonState00;
unsigned long DebounceDelay = 200;
unsigned long DebounceLast = 0;
void setup()
{
  pinMode(button,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(button),pinState,RISING);
  attachInterrupt(digitalPinToInterrupt(button00),Accident,RISING);
  dht.setup(A0); 
}

void Accident(){
  if((millis()-DebounceLast)>DebounceDelay){
    state00=!state00;
    DebounceLast=millis();
  }
}

void pinState(){
  if((millis()-DebounceLast)>DebounceDelay){
    state=!state;
    DebounceLast=millis();
  }
}
void loop()
{
  float humidity = dht.getHumidity(); 
  float temperature = dht.getTemperature(); 
  buttonState= digitalRead(button);
  buttonState00= digitalRead(button00);
  
  /*Serial.print("\tState : ");Serial.print(state);
  Serial.print("\tbuttonState :");Serial.println(buttonState);
  Serial.print("\tState00 : ");Serial.print(state00);
  Serial.print("\tbuttonState00 :");Serial.println(buttonState00);
  delay(500);*/
  if(state==LOW){
      Serial.println("\tSwitch turn off!");
      delay(1000);
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
  }

  else {
      Serial.print("\tHumipity :");Serial.print(humidity);
      Serial.print("\tTemperature :");Serial.print(temperature);Serial.print("*C");
      Serial.print("\t");Serial.print(dht.toFahrenheit(temperature));Serial.println("*F");
      delay(500);
      if((temperature>=0)&&(temperature<=28)){
        digitalWrite(led1,HIGH);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
      }
      else if((temperature>28)&&(temperature<=36)){
        digitalWrite(led1,LOW);
        digitalWrite(led2,HIGH);
        digitalWrite(led3,LOW);
        /*int pitch = map(500,100, 1000, 100, 2000); //ค่าที่เซ็นเซอร์อ่านค่าได้,ค่าต่ำสุด,ค่าสูงสุด,ความถี่ต่ำสุด 50Hz,ความถี่สูงสุด 4000Hz
        tone(8,pitch,100); //แสดงผลออกทางขาD8,ความถี่เท่ากับ pitch,ความยาวคาบหรือเสียงดังนานแค่ไหน  
        delay(100);*/
      }
      else if((temperature>36)&&(temperature<40)){
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,HIGH); 
        int pitch = map(500,100, 1000, 100, 2000); //ค่าที่เซ็นเซอร์อ่านค่าได้,ค่าต่ำสุด,ค่าสูงสุด,ความถี่ต่ำสุด 50Hz,ความถี่สูงสุด 4000Hz
        tone(8,pitch,100); //แสดงผลออกทางขาD8,ความถี่เท่ากับ pitch,ความยาวคาบหรือเสียงดังนานแค่ไหน  
        delay(100);
      }
       else if((temperature>=40)){
        state00==HIGH;
      }
  }
  if(state00==HIGH)
  { 
        state=LOW;
        Serial.println("\t!!!DANGER!!!");
        delay(100);
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,HIGH); 
        int pitch = map(500,100, 1000, 100, 2000); 
        tone(8,pitch,1000);
        delay(100);  
  }
  
}
