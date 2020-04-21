#define button 2

int i,led[8]={3,4,5,6,7,8,9,10};
int buttonState;
int state=0;
unsigned long DebounceDelay=200;
unsigned long DebounceLast=0;

void setup() {
  pinMode(led[i],OUTPUT);
  pinMode(button,INPUT);
  interrupts();
  attachInterrupt(digitalPinToInterrupt(button),PinState,RISING);
  
}
void PinState{
  if((millis()-DebouncedLast)>DebounceDelay){
    state++;
    millis()=DebounceLast;
  }
}
void loop() { 
  buttonState=digitalRead(button);
  if(buttonState==HIGH){
    for(int i=0;i<=7;i++){
    digitalWrite(led[i],HIGH);
    delay(100);
    digitalWrite(led[i],LOW);
    delay(100);
   }
  }
  else{
     for(int i=7;i>=0;i--){
    digitalWrite(led[i],HIGH);
    delay(100);
    digitalWrite(led[i],LOW);
    delay(100);
   }
  }
    
}
