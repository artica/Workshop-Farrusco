// --------------------------------------------------------------------------- LED RGB

int red_pin = 19;
int green_pin = 18;
int blue_pin = 17;

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
  
  ServoRange(60, 140, del, 5);
  
  ReadIR();
  
  BumperReader();
  
  if (BLeft == 1) 
  {
    Beco (1);
  }
  else if (BRight == 1) 
  {
    Beco (2);
  }
  else 
  {
  // se 'i' for menor do que 90 quer dizer que estamos a olhar para a esquerda
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da direita
  // girando apenas o motor da esquerda 
  if (i < 90) {
    
    if (IRValue >= 300)   {
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, HIGH);
      digitalWrite(blue_pin, LOW);
      
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;

      // slow down servo speed
      del = 250;
    }
    if(IRValue < 299) {
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, LOW);
      digitalWrite(blue_pin, HIGH);
      
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      
      // speed up servo speed
      del = 50;
    }
  }
  
  // se 'i' for maior do que 90 quer dizer que estamos a olhar para a direita
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
  // girando apenas o motor da direita 
  if (i > 90) {
    if (IRValue >= 300) {
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, HIGH);
      digitalWrite(blue_pin, LOW);
      
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;

      // slow down servo speed
      del = 250;
    }
    if(IRValue < 299) {
      digitalWrite(red_pin, LOW);
      digitalWrite(green_pin, LOW);
      digitalWrite(blue_pin, HIGH);
      
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      
      // speed up servo speed
      del = 50;
    }
  }
  delay(10);
  // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
  DiffTurn(motorLeftSpeed,motorRightSpeed);
 
  }
}

