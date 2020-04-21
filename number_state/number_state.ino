#define button 2

int buttonState;
int state ;
unsigned long DebounceDelay = 200;
unsigned long DebounceLast = 0;
unsigned long first = 3000;
unsigned long last = 0;
void setup() {
  pinMode(button,INPUT);
  interrupts();
  attachInterrupt(digitalPinToInterrupt(button),pinState,RISING);
  Serial.begin(9600);
}

void pinState()
{
  if((millis()-DebounceLast)>DebounceDelay)
  {
    state++;
    DebounceLast=millis(); 
  }
}

void loop() {
  buttonState = digitalRead(button);
  
   if((millis()-last)>first){
          Serial.print("State = "); Serial.println(state);
          delay(3000); 
          state = 0;
        }
         
}
