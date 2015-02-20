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
  
  delay(1000);
}

void loop() 
{
  
  ServoRange(60, 140, servoDelay, 5);
  
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
  // se 'servoPos' for menor do que 90 quer dizer que estamos a olhar para a esquerda
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da direita
  // girando apenas o motor da esquerda 
  if (servoPos > 90 && IRValue >= 300)   {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;
      // slow down servo speed
      servoDelay = 250;
    }
  
  // se 'servoPos' for maior do que 90 quer dizer que estamos a olhar para a direita
  // logo querermos que o robot se afaste, sendo assim vamos parar o motor da esquerda
  // girando apenas o motor da direita 
  if (servoPos < 90 && IRValue >= 300) {
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;
      // slow down servo speed
      servoDelay = 250;
    }
    
   if(IRValue < 299) {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      // speed up servo speed
      servoDelay = 50;
    }
  
  // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
  DiffTurn(motorLeftSpeed,motorRightSpeed);
 
  }
}

