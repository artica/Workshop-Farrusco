// --------------------------------------------------------------------------- SERVO
#include <Servo.h>
Servo s1;

// variaveis de direccao para o varrimento do servo
#define INCREMENTA_POSICAO  0
#define DECREMENTA_POSICAO  1

// variavel 'dir' (direcção) define a rotacao do servo
byte servoDir = INCREMENTA_POSICAO;

// o valor para ser enviado ao servo
// value to be sent to the servo
int servoPos = 90;
int max = 160;
int min = 20;
int actual = 0;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);

  s1.attach(9); // servo attach
  servoPos = 90;
  s1.write(servoPos); // center servo
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP

void loop() 
{

  // ServoRange (min, max, delay, increment) 
  ServoRange(20, 160, 100, 10);
}

