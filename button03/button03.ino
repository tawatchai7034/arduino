#define LED1 4
#define LED2 5
#define LED3 6
#define button 2

boolean  buttonState  ;
boolean State = LOW;
unsigned long DebounceDelay = 200;
unsigned long DebounceLast = 0; 

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(button,INPUT);
  interrupts();
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(button);
     if((millis()-DebounceLast)>DebounceDelay){
        if(buttonState == LOW){
        State = !State;
       }
         digitalWrite(LED1,State);
         digitalWrite(LED2,State);
         digitalWrite(LED3,State);
  
       //Serial.print("buttonState = "); Serial.println(buttonState);
       //delay(500);
       DebounceLast = millis(); 
       }     
}
