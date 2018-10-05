//#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
//#include <ir_Lego_PF_BitStreamEncoder.h>

/* 
source: www.electroschematics.com
You'll need to change the led pins and the codes 
accordingly to your configuration and IR remote
*/

#include <IRremote.h>
#include <IRremoteInt.h> 

int RECV_PIN = 11; // the pin where you connect the output pin of TSOP4838
int lmtA = 2;
int lmtB = 4;
int rmtA = 7;
int rmtB = 8;
int lEd = 13;

//int itsONled[] = {0,0,0,0};
/* the initial state of LEDs is OFF (zero) 
the first zero must remain zero but you can 
change the others to 1's if you want a certain
led to light when the board is powered */
#define fWd  6375 // code received from button A
#define rGht 23205 // code received from button B
#define lFt  4335 // code received from button C

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);   // you can comment this line
  irrecv.enableIRIn();  // Start the receiver
  pinMode(lmtA, OUTPUT);
  pinMode(lmtB, OUTPUT);
  pinMode(rmtA, OUTPUT);
  pinMode(rmtB, OUTPUT);
  pinMode(lEd, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    unsigned int value = results.value;
    switch(value) {
       case fWd:
         digitalWrite(lEd, HIGH);
          break; 
       case rGht:
         digitalWrite(lEd, LOW);
          break;
       case lFt:
         
          break;          
    }
    Serial.println(value); // you can comment this line
    irrecv.resume(); // Receive the next value
  }
}
