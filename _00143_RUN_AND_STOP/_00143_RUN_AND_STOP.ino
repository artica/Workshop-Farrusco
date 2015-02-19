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

int mappedValue;
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
  // read IR
  ReadIR();

  // choose one of the below functions
  StopAndGo();
  //ProgressiveStopAndGo();
}




