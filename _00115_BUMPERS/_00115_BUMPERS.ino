// --------------------------------------------------------------------------- BUMPERS
int bumperLeft = 8;
int bumperRight = 7;

int BLeft, BRight;

// --------------------------------------------------------------------------- SETUP

void setup() 
{
  Serial.begin(9600);
  
  
  // BUMPERS 
  // declare frontal bumpers as inputs
  pinMode (bumperLeft, INPUT);
  pinMode (bumperRight, INPUT);  
  
  // activate internal resistence of bumpers pins
  digitalWrite(bumperLeft, HIGH);
  digitalWrite(bumperRight, HIGH);
  
  delay(1000);
}

void loop() 
{
  BumperReader();
  delay(10);
}

