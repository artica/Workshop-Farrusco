// --------------------------------------------------------------------------- LDR
int LDRLeft_pin = 1;
int LDRRight_pin = 2;

int LDRLeft, LDRRight;

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

int min_speed = 150;

int motorLeftSpeed = 255;
int motorRightSpeed = 255;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  //declare motor pins as outputs
  pinMode(motorA0, OUTPUT);
  pinMode(motorA1, OUTPUT);
  pinMode(motorB0, OUTPUT);
  pinMode(motorB1, OUTPUT);

  // BUMPERS 
  // declare frontal bumpers as inputs
  pinMode (bumperLeft, INPUT);
  pinMode (bumperRight, INPUT);  
  
  // activate internal resistence of bumpers pins
  digitalWrite(bumperLeft, HIGH);
  digitalWrite(bumperRight, HIGH);
  
  delay(1000);
}

// --------------------------------------------------------------------------- LOOP
void loop() 
{
    
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
  
    // call 'DiffTurn' with motors speed
    LDRLeft = analogRead (LDRLeft_pin);
    LDRRight = analogRead (LDRRight_pin);
    Serial.print(LDRLeft);
    Serial.print("  ");
    Serial.println(LDRRight);
    // Farrusco will seek for light if the motorSpeedLeft is assigned the LDR_Right
    motorLeftSpeed = map (LDRLeft, 0, 1023, min_speed, maxSpeedLeft);
    motorRightSpeed = map (LDRRight, 0, 1023, min_speed, maxSpeedRight);
    
    DiffTurn(motorLeftSpeed, motorRightSpeed);
    delay(10);
  }
  
}

