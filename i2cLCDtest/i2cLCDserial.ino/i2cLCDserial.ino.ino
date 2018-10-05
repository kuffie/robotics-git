//https://forum.arduino.cc/index.php?topic=467084.0
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

int rOw = 0;
int cOl = 0;

void setup()
{
  lcd.init();                                        
  lcd.backlight();   

  Serial.begin(9600);  // Used to type in characters
  
// runs only once in setup
  // NOTE: Cursor Position: (CHAR, LINE) start at 0 
  lcd.print(" Hello, world!");            
  lcd.setCursor(0, 1);                   
  lcd.print("     WMCI");   
 
  // Display. (Set Serial Monitor option to "No Line Ending")
  lcd.clear();
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("Use Serial Mon");
  lcd.setCursor(0,1);
  lcd.print("Type to display");   
  delay(1000);
  lcd.clear();       
}

void loop()
{
  // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      //lcd.clear();
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        //lcd.setCursor(rOw,1);
        lcd.write(Serial.read());
        //rOw = rOw + 1;
        
      } 
}
}
