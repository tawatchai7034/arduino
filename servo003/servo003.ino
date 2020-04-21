#include <Servo.h>
Servo myServo;
#define LED1 4
#define LED2 5
#define Button 2

boolean buttonState;
int const potentPin = A0;
int potentVal;
int angle,i;
unsigned long DebounceDelay =200;
unsigned long DebounceLast =0;

  void setup()
  {
      pinMode(LED1,OUTPUT);
      pinMode(LED2,OUTPUT);
      pinMode(Button,INPUT);
      myServo.attach(9);
      Serial.begin(9600);
           
  }
  void loop()
  { 
      buttonState=digitalRead(Button);
      potentVal = analogRead(potentPin);
      //angle = map(potentVal,0,1023,0,179);
      if(buttonState==HIGH){
        for(int i=0;i<=180;i++){
           digitalWrite(LED1,HIGH);
           digitalWrite(LED2,LOW);
           myServo.write(i);
           delay(15);
           Serial.println(potentVal);
       }
      }
      else if(buttonState==LOW){
        for(int i=180;i>=0;i--){
           digitalWrite(LED1,LOW);
           digitalWrite(LED2,HIGH);
           myServo.write(i);
           delay(15);
           Serial.println(potentVal);
            }
      }       
  }
