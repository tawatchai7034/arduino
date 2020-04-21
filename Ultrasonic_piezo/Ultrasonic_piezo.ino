const int trigPin = 9;
const int echoPin = 10;
const int speakerPin = 8;
 
long duration;
int distance;
int beepCount = 0;
 
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(speakerPin, OUTPUT);
  Serial.begin(9600);
}
 
void loop() {
   
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
 
  distance = (duration * 0.034 )/ 2;
  if(distance<30){
     beep(distance);
  }
  print_distance(distance);
}

void beep(int distance) {
  beepCount += 12;
  if (beepCount / (distance * 10) > 1) {
    digitalWrite(speakerPin, LOW);
    //Serial.println("Open");
    beepCount = 0;
  }else if(beepCount > 50){
    digitalWrite(speakerPin, HIGH);
    //Serial.println("Close");
  }
}

void print_distance(int a){
      Serial.print("Distance: ");
      Serial.println(a);
      //delay(100);
  }
  
