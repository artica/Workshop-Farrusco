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
  
  ServoRange(60, 140, servoDelay, 5);
  
  ReadIR();
  
  // se estiver a olhar para a esquerda e se o valor do IR for superior a X 
  // entao vamos mudar de direccao
  if (servoPos > 90 && IRValue >= 300) {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;
      // slow servo
      servoDelay = 250;
  }
  
  // se estiver a olhar para a direita e se o valor do IR for superior a X 
  // entao vamos mudar de direccao
  if (servoPos < 90 && IRValue >= 300) {
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;
      // slow servo
      servoDelay = 250;
  }
  
  // caso contrario vamos andar em frente
  if(IRValue < 299) {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      // speed servo
      servoDelay = 50;
  }
  
  // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
  DiffTurn(motorLeftSpeed,motorRightSpeed);
 
  
}


/*
codigo antigo note-se a redundancia

// se estiver a olhar para a esquerda
if (servoPos > 90) {
    // se o valor do IR for superior a 300
    // entao vamos mudar de direccao
    if (IRValue >= 300)   {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = 0;
      // slow servo
      del = 250;
    }
    // caso contrario vamos andar em frente
    if(IRValue < 299) {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      // speed servo
      del = 50;
    }
  }
  // se estiver a olhar para a direita
  else if (servoPos < 90) {
    // se o valor do IR for superior a 300
    // entao vamos mudar de direccao
    if (IRValue >= 300) {
      motorRightSpeed = 0;
      motorLeftSpeed = maxSpeedLeft;
      // slow servo
      del = 250;
    }
    // caso contrario vamos mudar de direccao
    if(IRValue < 299) {
      motorRightSpeed = maxSpeedRight;
      motorLeftSpeed = maxSpeedLeft;
      // speed servo
      del = 50;
    }
  }
  
*/
