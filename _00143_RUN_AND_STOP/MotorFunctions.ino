// --------------------------------------------------------------------------- MOTORES DC

void MotorF() 
{
  DiffTurn(maxSpeedLeft, maxSpeedRight);  
  Serial.println("255, 255 - frente");
  delay(10);  
}


void MotorReverse() 
{  
  DiffTurn (-maxSpeedLeft, -maxSpeedRight);  
  Serial.println("-255, -255 - tras");
  delay(10);  
}

void MotorS() 
{
  DiffTurn (0, 0);  
  Serial.println("0, 0 - stop");
  delay(10);  
}

void MotorL() 
{
  DiffTurn (-maxSpeedLeft, maxSpeedRight);  
  Serial.println("-255, 255 - left");  
  delay(10);  
}
void MotorR() 
{  
  DiffTurn (maxSpeedLeft, -maxSpeedRight);  
  Serial.println("-255, -255 - tras");
  delay(10);  
}
