#define Leray1 4
#define Leray2 5
#define Leray3 6
#define Leray4 7

void setup() {
  pinMode(Leray1,OUTPUT);
  pinMode(Leray2,OUTPUT);
  pinMode(Leray3,OUTPUT);
  pinMode(Leray4,OUTPUT);

}

void loop() {
 digitalWrite(Leray1,HIGH);
 digitalWrite(Leray2,HIGH);
 digitalWrite(Leray3,HIGH);
 digitalWrite(Leray4,HIGH);
 delay(500);
 digitalWrite(Leray1,LOW);
 digitalWrite(Leray2,LOW);
 digitalWrite(Leray3,LOW);
 digitalWrite(Leray4,LOW);
 delay(500);
}
