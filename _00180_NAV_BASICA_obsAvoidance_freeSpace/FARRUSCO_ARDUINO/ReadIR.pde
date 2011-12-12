// --------------------------------------------------------------------------- INFRA RED SENSOR
int ReadIR() 
{
  IRValue = analogRead(IRPin);
  return IRValue;
}
