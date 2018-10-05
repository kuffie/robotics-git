//http://www.circuitbasics.com/how-to-set-up-an-ultrasonic-range-finder-on-an-arduino/

//#include <LiquidCrystal.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define trigPin 10 // 10
#define echoPin 13 // 13

//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int Rmota = 9;
const int Rmotb = 3;
const int Lmota = 6;
const int Lmotb = 5;

int threshr = 810;
int threshl = 850;
int HIGHspdR = 100;//255
int HIGHspdL = 150;//255
int LOWspd = 25;

  

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD 
  
  Serial.begin(9600);

  pinMode(Rmota, OUTPUT);
  pinMode(Rmotb, OUTPUT);
  pinMode(Lmota, OUTPUT);
  pinMode(Lmotb, OUTPUT);
/*
  // STOP
  analogWrite(Rmota, LOW);
  analogWrite(Rmotb, LOW);
  analogWrite(Lmota, LOW);
  analogWrite(Lmotb, LOW);
  */
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
  
  if (distance <= 20){
   /*
    Serial.print("OUT OF RANGE");
    lcd.setCursor(2,0);  //Set LCD cursor to upper left corner, column 0, row 0
    lcd.print("OUT OF RANGE");  //Print Message on First Row
    delay(500);
*/
   //BACKWARDS
  Serial.println("BACKWARDS");
  analogWrite(Rmota, 0);
  analogWrite(Rmotb, HIGHspdR);
  analogWrite(Lmota, 0);
  analogWrite(Lmotb, HIGHspdL);
  delay(1000);

  //RIGHT
  Serial.println("RIGHT");
  analogWrite(Rmota, 0);
  analogWrite(Rmotb, 0);
  analogWrite(Lmota, HIGHspdL);
  analogWrite(Lmotb, 0);

  delay(1000);
  return;
    
  }
  else {
    /*
    lcd.setCursor(3,0);
    lcd.print("ULTRASONIC");
    lcd.setCursor(4,1);
    lcd.print(distance);
    lcd.print(" cm");
    Serial.print(distance);
    Serial.println(" cm");
    delay(500);
    */
   //FORWARDS
  Serial.println("FORWARDS");
  analogWrite(Rmota, HIGHspdR);
  analogWrite(Rmotb, 0);
  analogWrite(Lmota, HIGHspdL);
  analogWrite(Lmotb, 0);
  delay(500);
    
  }
  
  //delay(500);
  //lcd.clear();
}
