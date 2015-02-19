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
  /*
  
  // acelera
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
      DiffTurn(-fadeValue, -fadeValue);  
      delay(50);
  }
  
  // desacelera
  for(int fadeValue = 255 ; fadeValue >= 0; fadeValue -=5) { 
    DiffTurn(fadeValue, -fadeValue);
    delay(50);
  }
 
  */
  DiffTurn(235, 255);  
  Serial.println("255, 255 - frente");
  delay(2000);  
  
  DiffTurn (255, -255);
  Serial.println("255, -255 - right");
  delay(250);  
}

