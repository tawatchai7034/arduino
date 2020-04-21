
const int sensorPin = A0;
const float baselineTemmp = 20.0;
int  i,LED[8]={3,4,5,6,7};

void setup() {
  Serial.begin(9600);
  for(int pinNumber = 3; pinNumber<8;pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber,LOW);
  }

}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("sensor Value : "); Serial.print(sensorVal);
  delay(500);

  float voltage=(sensorVal/1024.0)*5.0;
  Serial.print("Volts : "); Serial.print(voltage);
  delay(500);
  
  float temperature= (voltage-.5)*100;
  Serial.print(" degrees C: "); Serial.println(temperature);
  delay(500);
  
    if(temperature<baselineTemmp){
          for(i=0;i<=4;i++){
            digitalWrite(LED[i],HIGH);
            delay(100);
            digitalWrite(LED[i],LOW);
            delay(100);
          }
    }
    else if(temperature >= baselineTemmp+2 && temperature<baselineTemmp+4){
         for(i=4;i>=0;i--){
            digitalWrite(LED[i],HIGH);
            delay(100);
            digitalWrite(LED[i],LOW);
            delay(100);
          }
    }
}
