//http://www.circuitbasics.com/how-to-set-up-an-ultrasonic-range-finder-on-an-arduino/

//#include <LiquidCrystal.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define trigPin 2 // 10
#define echoPin 3 // 13

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD 
  
  Serial.begin(9600);
}

void loop() {
  float duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) * 0.0344;
  
  if (distance >= 180 || distance <= 2){
    Serial.print("OUT OF RANGE");
    lcd.setCursor(2,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("OUT OF RANGE");  //Print Message on First Row
    delay(500);
  }
  else {
    lcd.setCursor(3,0);
    lcd.print("ULTRASONIC");
    lcd.setCursor(4,1);
    lcd.print(distance);
    lcd.print(" cm");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
  }
  delay(500);
  lcd.clear();
}
