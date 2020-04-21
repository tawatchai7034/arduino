#define Leray1 4
#define Leray2 5
#define Leray3 6
#define Leray4 7
#define button 2
int state = 0 ;
int buttonState;
unsigned long DebounceDelay = 100;
unsigned long DebounceLast = 0;

void setup() {
  pinMode(button,INPUT);
  pinMode(Leray1,OUTPUT);
  pinMode(Leray2,OUTPUT);
  pinMode(Leray3,OUTPUT);
  pinMode(Leray4,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(button),pinState,RISING);

}

void pinState(){
  if((millis()-DebounceLast)>DebounceDelay){
     state++;
     DebounceLast=millis();
  }
}

void loop() {
  buttonState=digitalRead(button);

  Serial.print("\tState : ");
  Serial.print(state);
  Serial.print("\tbuttonState :");
  Serial.println(buttonState);
  delay(500);

  if(state==1){
     digitalWrite(Leray1,LOW);
     digitalWrite(Leray2,HIGH);
     digitalWrite(Leray3,HIGH);
     digitalWrite(Leray4,HIGH);
  }
  else if(state==2){
     digitalWrite(Leray1,HIGH);
     digitalWrite(Leray2,LOW);
     digitalWrite(Leray3,HIGH);
     digitalWrite(Leray4,HIGH);
  }
    else if(state==3){
     digitalWrite(Leray1,HIGH);
     digitalWrite(Leray2,HIGH);
     digitalWrite(Leray3,LOW);
     digitalWrite(Leray4,HIGH);
  }
    else if(state==4){
     digitalWrite(Leray1,HIGH);
     digitalWrite(Leray2,HIGH);
     digitalWrite(Leray3,HIGH);
     digitalWrite(Leray4,LOW);
  }
  else{
     digitalWrite(Leray1,HIGH);
     digitalWrite(Leray2,HIGH);
     digitalWrite(Leray3,HIGH);
     digitalWrite(Leray4,HIGH);
    state=0;
  }
 /*delay(500);
 digitalWrite(Leray1,LOW);
 digitalWrite(Leray2,LOW);
 digitalWrite(Leray3,LOW);
 digitalWrite(Leray4,LOW);
 delay(500);*/
}
