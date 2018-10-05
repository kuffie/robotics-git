/*
  Analog input, analog output, serial output

 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.

 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground

 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */

// These constants won't change.  They're used to give names
// to the pins used:
const int analogInPinL = A1;  // Analog input pin that the potentiometer is attached to
const int analogInPinC = A2;
const int analogInPinR = A3;

const int analogOutPinL = 9; // Analog output pin that the LED is attached to
const int analogOutPinC = 9;
const int analogOutPinR = 9;

int sensorValueL = 0;        // value read from the pot
int sensorValueC = 0;       
int sensorValueR = 0;       

int outputValueL = 0;        // value output to the PWM (analog out)
int outputValueC = 0;        
int outputValueR = 0;

int Rmota = 3;
int Rmotb = 4;
int Lmota = 5;
int Lmotb = 6;

int thresh = 700;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  pinMode(Rmota, OUTPUT);
  pinMode(Rmotb, OUTPUT);
  pinMode(Lmota, OUTPUT);
  pinMode(Lmotb, OUTPUT);

  // STOP
  digitalWrite(Rmota, LOW);
  digitalWrite(Rmotb, LOW);
  digitalWrite(Lmota, LOW);
  digitalWrite(Lmotb, LOW);
}

void loop() {
  // read the analog in value:
  sensorValueL = analogRead(analogInPinL);
  sensorValueC = analogRead(analogInPinC);
  sensorValueR = analogRead(analogInPinR);
  
  // print the results to the serial monitor:
  Serial.print("LEFT sensor = ");
  Serial.print(sensorValueL);
  Serial.print("   CENTER sensor = ");
  Serial.print(sensorValueC);
  Serial.print("   RIGHT sensor = ");
  Serial.println(sensorValueR);
  
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);

if ((sensorValueL < thresh) && (sensorValueC > thresh) && (sensorValueR < thresh))
  {
  //FORWARD
  Serial.println("FORWARD");
  digitalWrite(Rmota, HIGH);
  digitalWrite(Rmotb, LOW);
  digitalWrite(Lmota, HIGH);
  digitalWrite(Lmotb, LOW);
  }

if ((sensorValueL > thresh) && (sensorValueC < thresh) && (sensorValueR < thresh))
  {
  //LEFT
  Serial.println("LEFT");
  digitalWrite(Rmota, HIGH);
  digitalWrite(Rmotb, LOW);
  digitalWrite(Lmota, LOW);
  digitalWrite(Lmotb, LOW);
  }

if ((sensorValueL < thresh) && (sensorValueC < thresh) && (sensorValueR > thresh))
  {
  //RIGHT
  Serial.println("RIGHT");
  digitalWrite(Rmota, LOW);
  digitalWrite(Rmotb, LOW);
  digitalWrite(Lmota, HIGH);
  digitalWrite(Lmotb, LOW);
  }
  delay(1000);

}
