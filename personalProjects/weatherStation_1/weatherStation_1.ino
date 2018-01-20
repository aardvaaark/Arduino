#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int temperaturePin = A0;
const int numReadings = 200; 
int sensorVal = 0;
int readings[numReadings] = {0};  // initialize all the readings to 0:
int readIndex = 0;
unsigned long lastMillis = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(temperaturePin, INPUT);
  lcd.setCursor(0,1);
}

void loop() {
  
  sensorVal = analogRead(temperaturePin);
  float voltage = (sensorVal/1024.0) * 5.0;
  float temperatureC = (voltage - .5) * 100;
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

  Serial.print("TempC: ");
  Serial.println(temperatureC);
  Serial.print("TempF: ");
  Serial.println(temperatureF);
  
  lcd.clear();
  lcd.print("F:");
  lcd.print(temperatureF);
  lcd.setCursor(0,1);
   lcd.print("C:");
  lcd.print(temperatureC);

  delay(2000);

}
