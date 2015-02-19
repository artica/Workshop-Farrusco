// --------------------------------------------------------------------------- MOTORES DC

void MotorTest() 
{
  DiffTurn(255, 255);  
  Serial.println("255, 255");
  delay(1500);  
  DiffTurn (-255, -255);  
  Serial.println("-255, -255");
  delay(1500);  
  DiffTurn (0, 0);  
  Serial.println("0, 0");
  delay(1500);  
  DiffTurn (-255, 255);  
  Serial.println("-255, 255");  
  delay(1500);  
  DiffTurn (255, -255);
  Serial.println("255, -255");
  delay(1500);  
}
