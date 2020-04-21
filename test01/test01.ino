#define button 2

int i=0;
int LED[8]={3,4,5,6,7,8,9,10};
boolean  buttonState = LOW;
int state;
unsigned long DebounceDelay =50;
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
             state++;
             /*if(state>5)
             {
              state = 0;
              }*/
          }
      DebounceLast=millis();
     }     
       // Serial.print("State : "); Serial.println(state);
        //delay(100);
        
            if(state==0)
            {
              digitalWrite(LED[i],LOW);
              Serial.println("NO : 0");
              delay(100);
              }
            else if(state==1)
            {
                for(i=0;i<=7;i++)
                {
                  digitalWrite(LED[i],HIGH);
                  delay(100);
                  digitalWrite(LED[i],LOW);
                  delay(100);
                  Serial.println("NO : 1");
                  delay(100);
                  }
              
              }
              else if(state==2)
                { for(i=7;i>=0;i--)
                    {
                      digitalWrite(LED[i],HIGH);
                      delay(100);
                      digitalWrite(LED[i],LOW);
                      delay(100);
                      Serial.println("NO : 2");
                      delay(100);
                      }
                  }
              else if(state==3)
                      {
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
                        Serial.println("NO : 3");
                        delay(100);
                        }
     
  }
