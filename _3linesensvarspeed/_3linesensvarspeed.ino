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

int sensorValueL = 0;        // value read from the pot
int sensorValueC = 0;       
int sensorValueR = 0;       

int outputValueL = 0;        // value output to the PWM (analog out)
int outputValueC = 0;        
int outputValueR = 0;

const int Rmota = 3;
const int Rmotb = 9;
const int Lmota = 5;
const int Lmotb = 6;

int thresh = 800;
int HIGHspd = 150;
int LOWspd = 25;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  pinMode(analogInPinL, INPUT);
  pinMode(analogInPinC, INPUT);
  pinMode(analogInPinR, INPUT);

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
  //delay(2);


if ((sensorValueL > thresh) && (sensorValueC < thresh) && (sensorValueR < thresh))
  {
  //LEFT
  Serial.println("LEFT");
  analogWrite(Rmota, HIGHspd);
  analogWrite(Rmotb, 0);
  analogWrite(Lmota, 0);
  analogWrite(Lmotb, 0);

  //delay(500);

  return;
  }

if ((sensorValueL < thresh) && (sensorValueC < thresh) && (sensorValueR > thresh))
  {
  //RIGHT
  Serial.println("RIGHT");
  analogWrite(Rmota, 0);
  analogWrite(Rmotb, 0);
  analogWrite(Lmota, HIGHspd);
  analogWrite(Lmotb, 0);

  //delay(500);

  return;
  }

if ((sensorValueL < thresh) && (sensorValueC < thresh) && (sensorValueR > thresh))
  {
  //RIGHT
  Serial.println("RIGHT");
  analogWrite(Rmota, 0);
  analogWrite(Rmotb, 0);
  analogWrite(Lmota, HIGHspd);
  analogWrite(Lmotb, 0);

  //delay(500);

  return;
  }
  
  if ((sensorValueL < thresh) && (sensorValueC < thresh) && (sensorValueR < thresh))
  {
  
  //BACKWARDS
  Serial.println("BACKWARDS");
  analogWrite(Rmota, 0);
  analogWrite(Rmotb, HIGHspd);
  analogWrite(Lmota, 0);
  analogWrite(Lmotb, HIGHspd);
  //delay(500);

  return;
  }

  //FORWARDS
  Serial.println("FORWARDS");
  analogWrite(Rmota, HIGHspd);
  analogWrite(Rmotb, 0);
  analogWrite(Lmota, HIGHspd);
  analogWrite(Lmotb, 0);
  //delay(500);
  

}
