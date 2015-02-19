// --------------------------------------------------------------------------- INFRA RED SENSOR
void ReadIR() 
{
  IRValue = analogRead(IRPin);
//  Serial.println(IRValue);
  delay(40);
}
