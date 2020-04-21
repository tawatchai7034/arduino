#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int trigPin = 9;
const int echoPin = 10;

long duration;
float distance,Inch;

void setup() {
  lcd.begin(16, 2); // จอกว้าง 16 ตัวอักษร 2 บรรทัด
  lcd.setCursor(3, 0);
  lcd.print("Loading..."); // แสดงผลคำว่า Hello, world! ออกหน้าจอ
  lcd.setCursor(0, 1);
  for(int i=0;i<17;i++){
    lcd.print("*");
    delay(100);
  }
  delay(1000); // หน่วงเวลา 3 วินาที
  lcd.clear(); // ล้างหน้าจอ
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

  lcd.setCursor(4, 0);
  lcd.print("Distance");
  lcd.setCursor(0, 1);
  lcd.print(distance);lcd.print("CM. ");
  lcd.print(Inch);lcd.print("INC.");
  delay(500); // หน่วงเวลา 0.5 วินาที
  //lcd.clear(); // ล้างหน้าจอ
  //delay(500); // หน่วงเวลา 0.5 วินาที
}
