// --------------------------------------------------------------------------- MOTORES DC

// motor pins
int motorA0 = 6;
int motorA1 = 11;

int motorB0 = 3;
int motorB1 = 5;

// calibration variables, use it to perform a straight path
byte maxSpeedLeft = 255;
byte maxSpeedRight = 255;

int min_speed = 100;

// motorLeftSpeed, motorRightSpeed;

void MotorSetup() 
{
  //the motor control wires are outputs
  pinMode(motorA0, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorB0, OUTPUT);
  pinMode(motorB1, OUTPUT);

  
}
void MotorSetMaxVelocity(int speedLeft, int speedRight)
{
  maxSpeedLeft = speedLeft;
  maxSpeedRight = speedRight;  
}

void MotorDiffTurn(int _speedLeft, int _speedRight) {

 int speedLeft = map(_speedLeft, -255, 255, -maxSpeedLeft, maxSpeedLeft); 
 int speedRight = map(_speedRight, -255, 255, -maxSpeedRight, maxSpeedRight);

 if (speedLeft > 0) 
 {  
  analogWrite(motorB0, speedLeft);
  digitalWrite(motorB1, LOW);
 }
 
 if (speedLeft < 0) 
 {  
  digitalWrite(motorB0, LOW);
  analogWrite(motorB1, map(speedLeft, 0, -255, 0, 255));
 }
 
 if (speedLeft == 0) 
 {  
  digitalWrite(motorB0, LOW);
  digitalWrite(motorB1, LOW); 
 }
  
 if (speedRight > 0 ) 
 {
  analogWrite(motorA0, speedRight);
  digitalWrite(motorA1, LOW);
 }
 
 if (speedRight < 0 ) 
 {
  digitalWrite(motorA0, LOW);
  analogWrite(motorA1, map(speedRight, 0, -255, 0, 255));
 }
 
 if (speedRight == 0)
 {
  digitalWrite(motorA0, LOW);
  digitalWrite(motorA1, LOW);
 }
  
}

