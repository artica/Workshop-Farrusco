/*

  Change state when a time interval is achieved
  
  see blink without delays example: http://arduino.cc/en/Tutorial/BlinkWithoutDelay

*/


// --------------------------------------------------------------------------- TIME INTERVAL


// constants won't change. Used here to 
// set pin numbers:
const int ledPin =  13;      // the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
long previousMillis = 0;        // will store last time LED was updated

// the follow variables is a long because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long time_interval = 10000;           // interval at which to blink (milliseconds)


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
  
  // led 13
  pinMode (ledPin, OUTPUT);
  
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
  
  
  // update constante do tempo
  unsigned long currentMillis = millis();

  // se o tempo actual menos o tempo anterior for superior ao intervalo estabelecido 
  if(currentMillis - previousMillis > time_interval) {
    
    // guardar a ultima vez que o estado mudou 
    previousMillis = currentMillis;   

    // mudar de estado
    if (ledState == LOW) {
      ledState = HIGH;
      nav_state = 0;
    } else {
      ledState = LOW;
      nav_state = 1;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin, ledState);
  }
  
  Serial.print(currentMillis);
  Serial.print("  -  ");
  Serial.print(previousMillis);
  Serial.print("  =  ");
  Serial.print(currentMillis - previousMillis);
  Serial.print("    ledState:");
  Serial.println(ledState);
  
}

