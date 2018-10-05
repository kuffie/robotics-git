//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1

// GND to GND
// Vcc to 5V
// SDA to Analog 4
// SCL to Analog 5

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27 for a 16 chars and 2 line display
//LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 20 chars and 4 line display 

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("WALTER MURRAY");
  lcd.setCursor(4,1);
  lcd.print("ROBOTICS!");
   /* 
   lcd.setCursor(0,2);
  lcd.print("Arduino");
   lcd.setCursor(2,3);
  lcd.print("WMCI");
  */
  
}


void loop()
{
}
