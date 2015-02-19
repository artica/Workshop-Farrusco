/*  ----------------------------------------------------------------------------
 *  WWW.GUIBOT.PT                                                  WWW.ARTICA.CC
 *  ----------------------------------------------------------------------------
 *  FARRUSCO BASIC NAVIGATION
 *  ----------------------------------------------------------------------------
 *
 * Programa que Evita Obstaculos e testa funcionalidades basicas do Farrusco.
 * Os Delays foram removidos e agora usam-se intervalos de tempo com a biblioteca Metro,
 * isto possibilita a implementacao de computacao paralela.
 *
 *
 * This Obstacle Avoidance program tests Farrusco's basic features.  
 * Delays were removed and time intervals were added to perform parallel computing, 
 * Metro library is required. 
 *
 *
 *  Components                    Functions                Parameters
 *
 * - Servo                         ServoRange()             min, max, delay, increment
 * - Bumpers                       BumperReader()
 * - Infra-Red Sensor              ReadIR()
 *
*/

char val;

#define LED 13 // Define the led's pin
//Create a variable to hold theled's current state
int state = HIGH;

// --------------------------------------------------------------------------- METRO
#include <Metro.h>
Metro servoDelayMetro = Metro(25);
Metro bumperMetro = Metro(100); 
Metro sensorIRMetro = Metro(50); 
Metro serialMetro = Metro(50); 
Metro becoMetro = Metro(500); 
Metro ledMetro = Metro (250);

// --------------------------------------------------------------------------- SERVO
#include <Servo.h>
Servo servo;

#define INC_POS  0
#define DEC_POS  1

// variavel 'dir' (direcção) define a rotacao do servo
// variable 'dir' (direction) defines servo rotation 
byte servoDir = INC_POS;

// o valor para ser enviado ao servo
// value to be sent to the servo
int servoPos = 90;

// increment
int servoInc = 5;

// delay
int servoDel = 50;

int servoMin = 0;
int servoMax = 180;

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
int maxSpeedRight = 255;
int inByte = 'p';
char order = '1';
int isAssitedNavigation = 1;
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
  
  pinMode(LED, OUTPUT);
  
  delay(1000);
}




// --------------------------------------------------------------------------- LOOP

void loop() 
{
  HeartRate();
  
  if (Serial.available() > 0) 
  {
    inByte = Serial.read();
    if(inByte == '1') 
      order = inByte;
    if(inByte == '2') 
      order = inByte;
  }
    if(order == '1')
   { 
     isAssitedNavigation = 1;
      AssistedNavigation();
   }
    else if(order == '2') 
    {
      isAssitedNavigation = 0;
      obstacleAvoidanceUpdate();
    }

}

