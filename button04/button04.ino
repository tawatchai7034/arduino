#define led 3
#define button 2

boolean state =LOW ;
int buttonState;
unsigned long DebounceDelay = 200;
unsigned long DebounceLast = 0;
void setup() {
  pinMode(button,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(button),pinState,RISING);
}

void pinState(){
  if((millis()-DebounceLast)>DebounceDelay){
     state=!state;
     DebounceLast=millis();
  }
}
void loop() {
  buttonState=digitalRead(button);

  digitalWrite(led,state);
  Serial.print("\tState : ");
  Serial.print(state);
  Serial.print("\tbuttonState :");
  Serial.println(buttonState);
  delay(500);
}
