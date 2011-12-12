// --------------------------------------------------------------------------- INFRA RED SENSOR
void ReadIR() 
{
  IRValue = analogRead(IRPin);
  delay(20);
  
  Serial.println(IRValue);
  
}
