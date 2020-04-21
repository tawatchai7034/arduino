#define button 2

int i=0;
int LED[8]={3,4,5,6,7,8,9,10};
boolean  buttonState = LOW;
int State;
unsigned long DebounceDelay =100;
unsigned long DebounceLast=0;

void setup() {
  pinMode(LED[i],OUTPUT);
  pinMode(button,INPUT);
  interrupts();
  //attachInterrupt(digitalPinToInterrupt(button),PinState,RISING);
  for(i=0;i<7;i++);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(button);
  if((millis()-DebounceLast)>DebounceDelay)
    {
           if(buttonState == HIGH)
           {
             State++;
             if(State>=4)
             {
              State = 0;
              }
          }
      DebounceLast=millis();
     }     
    if(State==0){
      Serial.println("STATE : 0");
      delay(100);
         digitalWrite(LED[0],HIGH);
         delay(100);
         digitalWrite(LED[1],HIGH);
         delay(100);
         digitalWrite(LED[2],HIGH);
         delay(100);
         digitalWrite(LED[3],HIGH);
         delay(100);
         digitalWrite(LED[4],HIGH);
         delay(100);
         digitalWrite(LED[5],HIGH);
         delay(100);
         digitalWrite(LED[6],HIGH);
         delay(100);
         digitalWrite(LED[7],HIGH);
         delay(100);
         digitalWrite(LED[0],LOW);
         delay(100);
         digitalWrite(LED[1],LOW);
         delay(100);
         digitalWrite(LED[2],LOW);
         delay(100);
         digitalWrite(LED[3],LOW);
         delay(100);
         digitalWrite(LED[4],LOW);
         delay(100);
         digitalWrite(LED[5],LOW);
         delay(100);
         digitalWrite(LED[6],LOW);
         delay(100);
         digitalWrite(LED[7],LOW);
         delay(100);
    
         digitalWrite(LED[7],HIGH);
         delay(100);
         digitalWrite(LED[6],HIGH);
         delay(100);
         digitalWrite(LED[5],HIGH);
         delay(100);
         digitalWrite(LED[4],HIGH);
         delay(100);
         digitalWrite(LED[3],HIGH);
         delay(100);
         digitalWrite(LED[2],HIGH);
         delay(100);
         digitalWrite(LED[1],HIGH);
         delay(100);
         digitalWrite(LED[0],HIGH);
         delay(100);
         digitalWrite(LED[7],LOW);
         delay(100);
         digitalWrite(LED[6],LOW);
         delay(100);
         digitalWrite(LED[5],LOW);
         delay(100);
         digitalWrite(LED[4],LOW);
         delay(100);
         digitalWrite(LED[3],LOW);
         delay(100);
         digitalWrite(LED[2],LOW);
         delay(100);
         digitalWrite(LED[1],LOW);
         delay(100);
         digitalWrite(LED[0],LOW);
         delay(100);
          
    }
     else if(State==1) {
        Serial.println("STATE : 1");
        delay(100);
         digitalWrite(LED[0],HIGH);
         delay(100);
         digitalWrite(LED[7],HIGH);
         delay(100);
         digitalWrite(LED[1],HIGH);
         delay(100);
         digitalWrite(LED[6],HIGH);
         delay(100);
         digitalWrite(LED[2],HIGH);
         delay(100);
         digitalWrite(LED[5],HIGH);
         delay(100);
         digitalWrite(LED[3],HIGH);
         delay(100);
         digitalWrite(LED[4],HIGH);
         delay(100);
         digitalWrite(LED[0],LOW);
         delay(100);
         digitalWrite(LED[7],LOW);
         delay(100);
         digitalWrite(LED[1],LOW);
         delay(100);
         digitalWrite(LED[6],LOW);
         delay(100);
         digitalWrite(LED[2],LOW);
         delay(100);
         digitalWrite(LED[5],LOW);
         delay(100);
         digitalWrite(LED[3],LOW);
         delay(100);
         digitalWrite(LED[4],LOW);
         delay(100);

         digitalWrite(LED[3],HIGH);
         delay(100);
         digitalWrite(LED[4],HIGH);
         delay(100);
         digitalWrite(LED[2],HIGH);
         delay(100);
         digitalWrite(LED[5],HIGH);
         delay(100);
         digitalWrite(LED[1],HIGH);
         delay(100);
         digitalWrite(LED[6],HIGH);
         delay(100);
         digitalWrite(LED[0],HIGH);
         delay(100);
         digitalWrite(LED[7],HIGH);
         delay(100);
         digitalWrite(LED[3],LOW);
         delay(100);
         digitalWrite(LED[4],LOW);
         delay(100);
         digitalWrite(LED[2],LOW);
         delay(100);
         digitalWrite(LED[5],LOW);
         delay(100);
         digitalWrite(LED[1],LOW);
         delay(100);
         digitalWrite(LED[6],LOW);
         delay(100);
         digitalWrite(LED[0],LOW);
         delay(100);
         digitalWrite(LED[7],LOW);
         delay(100);
          
      }
     else if(State==2) {
        Serial.println("STATE : 2");
        delay(100);
           digitalWrite(LED[0],HIGH);
           delay(100);
           digitalWrite(LED[1],HIGH);
           delay(100);
           digitalWrite(LED[2],HIGH);
           delay(100);
           digitalWrite(LED[3],HIGH);
           delay(100);
           digitalWrite(LED[0],LOW);
           delay(100);
           digitalWrite(LED[1],LOW);
           delay(100);
           digitalWrite(LED[2],LOW);
           delay(100);
           digitalWrite(LED[3],LOW);
           delay(100);
          digitalWrite(LED[0],HIGH);
          digitalWrite(LED[1],HIGH);
          digitalWrite(LED[2],HIGH);
          digitalWrite(LED[3],HIGH);
          delay(100);
          digitalWrite(LED[0],LOW);
          digitalWrite(LED[1],LOW);
          digitalWrite(LED[2],LOW);
          digitalWrite(LED[3],LOW);
          delay(100);
          digitalWrite(LED[0],LOW);
          digitalWrite(LED[1],LOW);
          digitalWrite(LED[2],LOW);
          digitalWrite(LED[3],LOW);
          delay(100);
        
         digitalWrite(LED[4],HIGH);
         delay(100);
         digitalWrite(LED[5],HIGH);
         delay(100);
         digitalWrite(LED[6],HIGH);
         delay(100);
         digitalWrite(LED[7],HIGH);
         delay(100);
         digitalWrite(LED[4],LOW);
         delay(100);
         digitalWrite(LED[5],LOW);
         delay(100);
         digitalWrite(LED[6],LOW);
         delay(100);
         digitalWrite(LED[7],LOW);
         delay(100);
        digitalWrite(LED[4],HIGH);
        digitalWrite(LED[5],HIGH);
        digitalWrite(LED[6],HIGH);
        digitalWrite(LED[7],HIGH);
        delay(100);
        digitalWrite(LED[4],LOW);
        digitalWrite(LED[5],LOW);
        digitalWrite(LED[6],LOW);
        digitalWrite(LED[7],LOW);
        delay(100);
        digitalWrite(LED[4],LOW);
        digitalWrite(LED[5],LOW);
        digitalWrite(LED[6],LOW);
        digitalWrite(LED[7],LOW);
        delay(100);
      }
      else if(State==3){
        Serial.println("STATE : 3");
        delay(100);
        for(int i=0;i<=7;i++){
          digitalWrite(LED[i],LOW);
        }
      }
  }
