#define led0 2
#define led1 3
#define led2 4
#define led3 5
#define led4 6
#define led5 7
#define TilT 8

int i;
void setup() {
 pinMode(led0,OUTPUT);
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);
 pinMode(led5,OUTPUT);
 pinMode(TilT,INPUT);
 //digitalWrite(led,LOW);
}

void loop() {
  if(digitalRead(TilT)==1){
      digitalWrite(led0,HIGH);
      delay(200);
      digitalWrite(led1,HIGH);
      delay(200);
      digitalWrite(led2,HIGH);
      delay(200);
      digitalWrite(led3,HIGH);
      delay(200);
      digitalWrite(led4,HIGH);
      delay(500);
      digitalWrite(led5,HIGH);
      delay(500);
      
      digitalWrite(led0,LOW);
      delay(500);
      digitalWrite(led1,LOW);
      delay(500);
      digitalWrite(led2,LOW);
      delay(500);
      digitalWrite(led3,LOW);
      delay(500);
      digitalWrite(led4,LOW);
      delay(500);
      digitalWrite(led5,LOW);
      delay(500);
  }
  else
  {
      digitalWrite(led5,HIGH);
      delay(500);
      digitalWrite(led4,HIGH);
      delay(500);
      digitalWrite(led3,HIGH);
      delay(500);
      digitalWrite(led2,HIGH);
      delay(500);
      digitalWrite(led1,HIGH);
      delay(500);
      digitalWrite(led0,HIGH);
      delay(500);
      
      digitalWrite(led5,LOW);
      delay(500);
      digitalWrite(led4,LOW);
      delay(500);
      digitalWrite(led3,LOW);
      delay(500);
      digitalWrite(led2,LOW);
      delay(500);
      digitalWrite(led1,LOW);
      delay(500);
      digitalWrite(led0,LOW);
      delay(500);
    }
}
