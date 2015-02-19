// --------------------------------------------------------------------------- SERVO
#include <Servo.h>
Servo servo;

#define INC_POS  0
#define DEC_POS  1

// variavel 'dir' (direcção) define a rotacao do servo
// variable 'dir' (direction) defines servo rotation 
byte dir = INC_POS;

// o valor para ser enviado ao servo
// value to be sent to the servo
int i = 90;

// increment
int inc = 5;

// delay
int del = 50;


// --------------------------------------------------------------------------- MOTORES DC

// motor pins
int motorA0 = 6;
int motorA1 = 11;

int motorB0 = 3;
int motorB1 = 5;

// calibration variables, use it to perform a straight path
int maxSpeedLeft = 235;
int maxSpeedRight = 255;

int min_speed = 100;

int motorLeftSpeed, motorRightSpeed;

// --------------------------------------------------------------------------- IR SENSOR
int IRPin = 0;
int IRValue;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  //the motor control wires are outputs
  pinMode(motorA0, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorB0, OUTPUT);
  pinMode(motorB1, OUTPUT);

  servo.attach(9); // servo attach
  servo.write(90); // center servo
  
  
  delay(1000);
}

void loop() 
{
  
  ServoRange(60, 140, del, 5);
  
  ReadIR();
  
  if (i > 90) {
    if (IRValue >= 300)   {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;
      del = 250;
    }
    if(IRValue < 299) {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      del = 50;
    }
  }
  else if (i < 90) {
    if (IRValue >= 300) {
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;
      del = 250;
    }
    if(IRValue < 299) {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      del = 50;
    }
  }
  
  // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
  DiffTurn(motorLeftSpeed,motorRightSpeed);
 
  
}

