#define led1 4
#define led2 5
#define led3 6
#define button 2

int buttonState;
unsigned long debounceDelay = 200;
unsigned long debounceLast = 0;
void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(button,INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState =  digitalRead(button);

  if((millis()-debounceLast)>debounceDelay){
        if(buttonState == HIGH ){
              digitalWrite(led1,HIGH);
              digitalWrite(led2,LOW);
              digitalWrite(led3,LOW);
              delay(500);
              digitalWrite(led1,LOW);
              digitalWrite(led2,HIGH);
              digitalWrite(led3,LOW);
              delay(500);
              digitalWrite(led1,LOW);
              digitalWrite(led2,LOW);
              digitalWrite(led3,HIGH);
              delay(500); 
              Serial.println("HIGH");
              delay(500);
          }
          else
          {
              digitalWrite(led1,LOW);
              digitalWrite(led2,LOW);
              digitalWrite(led3,HIGH);
              delay(500);
              digitalWrite(led1,LOW);
              digitalWrite(led2,HIGH);
              digitalWrite(led3,LOW);
              delay(500);
              digitalWrite(led1,HIGH);
              digitalWrite(led2,LOW);
              digitalWrite(led3,LOW);
              delay(500); 
              Serial.println("LOW");
              delay(500);
          }
  }
}
