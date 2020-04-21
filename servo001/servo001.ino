#include <Servo.h>
Servo myServo;
int const potentPin = A0;
int potentVal;
int angle;
void setup()
{
myServo.attach(9);
Serial.begin(9600);
}
void loop()
{
potentVal = analogRead(potentPin);
Serial.print("PotentVal : "); Serial.print(potentVal);
delay(500);
angle = map(potentVal,0,1023,0,179);
Serial.print("\tangle : ");Serial.println(angle);
delay(500);
myServo.write(0);
delay(15);
}
