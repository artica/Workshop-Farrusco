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
  
 // utiliza a funçao DiffTurn para fazer o Farrusco desenhar um quadrado no chao
 // tenta faze-lo com o minimo de linhas de codigo possivel
 
 
}

