//Тестировалось на Arduino IDE 1.0.5
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  

void setup()
{
  lcd.init();                            // Инициализация lcd             
  lcd.backlight();                       // Включаем подсветку
  
// runs only once in setup
  lcd.print(" Hello, world!");            // Выводим текст
  lcd.setCursor(0, 1);                   // Устанавливаем курсор в начало 2 строки
  lcd.print("     WMCI");              // Выводим текст
}

void loop()
{
}
