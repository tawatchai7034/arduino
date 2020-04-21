int sensorValue; 
int sensorLow = 1023; 
int sensorHigh = 0; 
const int ledPin = 13; 
void setup() { 
  Serial.begin(9600); 
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, HIGH); 
  
  while (millis() < 5000) { 
  sensorValue = analogRead(A0);
  if (sensorValue > sensorHigh) 
  { 
    sensorHigh = sensorValue; 
    } 
  if (sensorValue < sensorLow)
  { 
    sensorLow = sensorValue;
    } 
  Serial.print("SensorLow = ");Serial.print(sensorLow); 
  Serial.print(", SensorHigh = "); Serial.print(sensorHigh); 
  Serial.print(", Sensor Value= ");  Serial.println(sensorValue); 
  delay(1000);
  } 
  digitalWrite(ledPin, LOW); 
  } 

void loop() { 
  sensorValue = analogRead(A0); 
  Serial.println("Sensor Values"); 
  Serial.print("\tSensorLow = ");  Serial.print(sensorLow); 
  Serial.print("\tSensorHigh = "); Serial.print(sensorHigh); 
  Serial.print("\tSensor Value= "); Serial.println(sensorValue); 
  delay(1000);
  int pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000); //ค่าที่เซ็นเซอร์อ่านค่าได้,ค่าต่ำสุด,ค่าสูงสุด,ความถี่ต่ำสุด 50Hz,ความถี่สูงสุด 4000Hz
  tone(8,pitch,100); //แสดงผลออกทางขาD8,ความถี่เท่ากับ pitch,ความยาวคาบหรือเสียงดังนานแค่ไหน  
  delay(100); 
  } 
