#include <LiquidCrystal.h>
int tempPin = 0; 
const int p_trig = 3;
const int p_echo = 2;
#define sensorgas A1
float sensor_value;
float printable_value;
LiquidCrystal lcd(7,6,5,4,8,9);


void setup() {
  lcd.begin(16,2);
  lcd.clear();
  Serial.begin(9600);
  Serial.println("Sensor de Gas Ligado");
  pinMode(p_trig,OUTPUT);
  pinMode(p_echo,INPUT);
}
 
void loop() {
  delay(100);
  long duration, cm;
  int reading = analogRead(tempPin);  

  float voltage = reading * 5.0;
  voltage /= 1024.0; 
  
  //SENSOR DE GAS
  int sensor_value = analogRead(sensorgas);
 	printable_value = analogRead(sensorgas);
  	Serial.print(printable_value);
  	Serial.print(" PPM");
	Serial.println();
  	delay(1000);


  digitalWrite(p_trig,LOW);
  delayMicroseconds(2);
  digitalWrite(p_trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(p_trig,LOW);
  
  duration = pulseIn(p_echo,HIGH);

  cm = microsecondsToCentimeters(duration);

  float temperatureC = (voltage - 0.5) * 100 ; 
  Serial.print(cm); Serial.print("cm | ");
  Serial.print(temperatureC); Serial.print(" Celsius");
  Serial.println();
 
  lcd.setCursor(1,0);
  lcd.print(temperatureC);lcd.print('C');
  lcd.setCursor(9,0);
  lcd.print(cm);
  lcd.setCursor(12,0);
  lcd.print("cm");
  lcd.setCursor(3,1);
  lcd.print(printable_value);
  lcd.setCursor(10,1);
  lcd.print("PPM");
  delay(1000);

  delay(1000);
}

long microsecondsToInches(long microseconds) {

  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {

  return microseconds / 29 / 2;
}
