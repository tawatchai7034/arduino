#include <LiquidCrystal.h>
#include "DHT.h"

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // RS, E, D4, D5, D6, D7
DHT dht;

void setup() {
  lcd.begin(16, 2); // จอกว้าง 16 ตัวอักษร 2 บรรทัด
  lcd.print("LCDisplay"); // แสดงผลคำว่า Hello, world! ออกหน้าจอ
  lcd.setCursor(0, 1); // เลื่อนเคเซอร์ไปบรรทัดที่ 2 ลำดับที่ 0 (ก่อนหน้าตัวอักษรแรก)
  lcd.print("www.ioxhop.com"); // แสดงผลคำว่า www.ioxhop.com
  delay(3000); // หน่วงเวลา 3 วินาที
  lcd.clear(); // ล้างหน้าจอ
  dht.setup(A0);
}

void loop() {
  float humidity = dht.getHumidity(); 
  float temperature = dht.getTemperature();
  lcd.setCursor(0, 0);
  lcd.print("Humidity:");lcd.print(humidity);
  lcd.setCursor(0, 1);
  lcd.print("Temperature:");lcd.print(temperature);
  delay(500); // หน่วงเวลา 0.5 วินาที
  //lcd.clear(); // ล้างหน้าจอ
 // delay(500); // หน่วงเวลา 0.5 วินาที
}
