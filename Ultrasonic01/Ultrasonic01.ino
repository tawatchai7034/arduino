const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance,Inch;
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop() {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Inch=distance*0.3937;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" CM.\t");
  Serial.print(Inch);
  Serial.println(" INC."); 
  delay(100); 
}
