/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 * https://arduino-info.wikispaces.com/IR-RemoteControl?responseToken=8a120bc9121772048478024f7aaad0e3
 * When lookong at the sensor the pins are numbered from left to right
 * pin 1 is sig and goes to pin 11 on the Arduino
 * pin 2 is GND
 * pin 3 is Vcc
 */

#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}

