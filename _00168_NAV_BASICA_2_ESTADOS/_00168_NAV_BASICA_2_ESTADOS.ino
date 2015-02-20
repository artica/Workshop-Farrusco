/*
 
  Change state when a bumper is pressed
  
  nav_state is changed inside Beco() function

*/

// --------------------------------------------------------------------------- NAVIGATION STATE

// 0 = obstacle avoidance
// 1 = follow light
int nav_state = 0;

// --------------------------------------------------------------------------- LDR
int LDRLeft_pin = 1;
int LDRRight_pin = 2;

int LDRLeft, LDRRight;

// --------------------------------------------------------------------------- LED RGB

int red_pin = 19;
int green_pin = 18;
int blue_pin = 17;

// --------------------------------------------------------------------------- SERVO
#include <Servo.h>
Servo servo;

#define INCREMENTA_POSICAO  0
#define DECREMENTA_POSICAO  1

// variavel 'dir' (direcção) define a rotacao do servo
// variable 'dir' (direction) defines servo rotation 
byte servoDir = INCREMENTA_POSICAO;

// o valor para ser enviado ao servo
// value to be sent to the servo
int servoPos = 90;

// servo increment
int servoInc = 5;

// servo delay
int servoDelay = 50;

// --------------------------------------------------------------------------- BUMPERS
int bumperLeft = 8;
int bumperRight = 7;

int BLeft, BRight;

// --------------------------------------------------------------------------- MOTORES DC

// motor pins
int motorA0 = 6;
int motorA1 = 11;

int motorB0 = 3;
int motorB1 = 5;

// calibration variables, use it to perform a straight path
int maxSpeedLeft = 255;
int maxSpeedRight = 210;

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
  
  // frontal bumpers
  pinMode (bumperLeft, INPUT);
  pinMode (bumperRight, INPUT);  
  // activate internal resistence
  digitalWrite(bumperLeft, HIGH);
  digitalWrite(bumperRight, HIGH);
  
  // led rgb
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
    
  delay(1000);
}

void loop() 
{
  
  if (nav_state == 0) 
  {
    ObstacleAvoidance();
  }
  else 
  {
    FollowLight();
  }
  
}

