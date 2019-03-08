#include "DHT.h"
#include <LiquidCrystal_I2C.h>
#define DHTPin 3//défini DHT pin
#define DHTTYPE DHT11
DHT dht(DHTPin, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);
byte temp = 0;
void setup() {
  lcd.init();
  lcd.backlight();
  lcd.print("I Will Survive");
  lcd.begin(16,2); 
  Serial.begin(9600);
  dht.begin();
}
void loop() {
  temp = digitalRead(2);
  

  
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  delay(100); //
  Serial.println(t);
  delay(1000);
  
  lcd.cursor_on();
  lcd.blink_on();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("Humi: ");
  lcd.print(h);
  lcd.print(" %");
  delay(2000);
}
