// --------------------------------------------------------------------------- SERVO
#include <Servo.h>
Servo servo;

// variaveis de direccao para o varrimento do servo
#define INC_POS  0
#define DEC_POS  1

// variavel 'dir' (direcção) define a rotacao do servo
byte dir = INC_POS;

// o valor para ser enviado ao servo
// value to be sent to the servo
int i = 90;

// increment
int inc = 5;

// delay
int del = 50;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);

  servo.attach(9); // servo attach
  servo.write(90); // center servo
  
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP

void loop() 
{
  
  // ServoRange (min, max, delay, increment) 
  ServoRange(60, 140, 25, 2);

}

