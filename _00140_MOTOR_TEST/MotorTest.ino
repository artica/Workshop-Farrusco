// --------------------------------------------------------------------------- MOTORES DC

void MotorTest() 
{ 
  DiffTurn(255, 255);  
  Serial.println("255, 255 - frente");
  delay(1500);  
  
  DiffTurn (-255, -255);  
  Serial.println("-255, -255 - tras");
  delay(1500);  
  
  DiffTurn (0, 0);  
  Serial.println("0, 0 - stop");
  delay(1500);  
  
  DiffTurn (-255, 255);  
  Serial.println("-255, 255 - left");  
  delay(1500);  
  
  DiffTurn (255, -255);
  Serial.println("255, -255 - right");
  delay(1500);  
 
}
