/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/

// MOTOR CONTROLLER TEST
int rmota = 3; // RIGHT MOTOR
int rmotb = 4;
int lmota = 5; // LEFT MOTOR
int lmotb = 6;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(rmota, OUTPUT);
  pinMode(rmotb, OUTPUT);
  pinMode(lmota, OUTPUT);
  pinMode(lmotb, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(rmota, LOW);   //STOP
  digitalWrite(rmotb, LOW);
  digitalWrite(lmota, LOW);
  digitalWrite(lmotb, LOW);
  delay(1000);                       // wait for a second

  digitalWrite(rmota, HIGH);   //FORWARD
  digitalWrite(rmotb, LOW);
  digitalWrite(lmota, HIGH);
  digitalWrite(lmotb, LOW);
  delay(5000);                       // wait for a second
  
}
