//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Ultrasonic.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Ultrasonic ultrasonic(12, 13);  // TRIG 12, ECHO 13

long duration, distance; // Duration used to calculate distance

void setup()
{
  lcd.init();                      // initialize the lcd 
  
  lcd.backlight();

 Serial.begin(9600); 
 
}


void loop()
{
    // Print a message to the LCD.
   lcd.setCursor(0,0);
  
  lcd.print("Distance in CM: ");
  Serial.print("Distance in CM: ");
  lcd.setCursor(2,1);
  lcd.print(ultrasonic.distanceRead()); 
  // Pass INC as a parameter to get the distance in inches
  Serial.println(ultrasonic.distanceRead());
  delay(10);
  
}
