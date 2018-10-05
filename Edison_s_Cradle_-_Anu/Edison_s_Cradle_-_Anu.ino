/* 
https://www.youtube.com/watch?v=vzc6K8ui-To
https://learn.adafruit.com/adafruit-arduino-lesson-4-eight-leds/the-74hc595-shift-register
https://programmingelectronics.com/tutorial-12-for-loop-iteration/
https://www.arduino.cc/reference/en/language/structure/control-structure/for/
https://www.arduino.cc/reference/en/language/structure/compound-operators/increment/
https://www.reddit.com/r/arduino/comments/9it8j8/help_recreating_a_newtons_cradle_electrically_how/
*/


int latchPin = 5;
int clockPin = 6;
int dataPin = 4;
byte LEDs = 0; 
int i = 0;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);

  Serial.begin(9600);
}
 
void loop() 
{
  
  
  up();
  dn();
  Serial.println();
}

void up()
{
 LEDs = 0;
  updateShiftRegister();
  delay(50);
  for (int i = 0; i < 8; i++)
  {
    bitSet(LEDs, i);
    updateShiftRegister();
    delay(50);
  }
}

void dn(i)
{
LEDs = 0;
  updateShiftRegister();
  delay(50);
  for (int i = 0; i < 8; i++)
  {
    bitSet(LEDs, i);
    updateShiftRegister();
    delay(50);
  }
}

void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
   digitalWrite(latchPin, HIGH);
}
