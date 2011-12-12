// --------------------------------------------------------------------------- MOTORES DC

void MotorF() 
{
  DiffTurn(255, 255);  
  Serial.println("255, 255 - frente");
  delay(10);  
}


void MotorR() 
{  
  DiffTurn (-255, -255);  
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
  DiffTurn (-255, 255);  
  Serial.println("-255, 255 - left");  
  delay(10);  
}

void MotorR() 
{
  DiffTurn (255, -255);
  Serial.println("255, -255 - right");
  delay(10);  
}
