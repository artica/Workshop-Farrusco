// --------------------------------------------------------------------------- PIEZO




// --------------------------------------------------------------------------- MOTORES DC

// motor pins
int motorA0 = 6;
int motorA1 = 11;

int motorB0 = 3;
int motorB1 = 5;
 
// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  //the motor control wires are outputs
  pinMode(motorA0, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorB0, OUTPUT);
  pinMode(motorB1, OUTPUT);
  
  delay(1000);
}

void loop() 
{
  
  stopMotor();
  delay(1000);
  forwardMotor();
  delay(1000);
  turnRightMotor();
  delay(1000);
  turnLeftMotor();
  delay(1000);
  backwardMotor();
  delay(1000);
  
  //MotorTest();
} 
  
void stopMotor(){
  Serial.println("stop");
  analogWrite(motorA0, 0);
  analogWrite(motorA1, 0);
 
  analogWrite(motorB0, 0);
  analogWrite(motorB1, 0);
}
void forwardMotor(){
  Serial.println("forward");
  analogWrite(motorA0, 255);
  analogWrite(motorA1, 0);
 
  analogWrite(motorB0, 255);
  analogWrite(motorB1, 0);
}
    
void backwardMotor(){
  Serial.println("backward");
  analogWrite(motorB0, 0);
  analogWrite(motorB1, 255);
 
  analogWrite(motorA0, 0);
  analogWrite(motorA1, 255); 
}

void turnRightMotor(){
  Serial.println("turnright");
  analogWrite(motorB0, 255);
  analogWrite(motorB1, 0);
  
  analogWrite(motorA0, 0);
  analogWrite(motorA1, 255);
 } 
 
void turnLeftMotor(){
  Serial.println("turnleft");
 analogWrite(motorB0, 0);
 analogWrite(motorB1, 255);
 
 analogWrite(motorA0, 255);
 analogWrite(motorA1, 0);
}
