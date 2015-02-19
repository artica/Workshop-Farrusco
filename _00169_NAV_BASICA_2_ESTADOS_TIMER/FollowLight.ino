void FollowLight() 
{
   BumperReader();
  
  if (BLeft == 1) 
  {
    Beco (1);
  }
  else if (BRight == 1) 
  {
    Beco (2);
  }
  else 
  {
  
  // call 'DiffTurn' with motors speed
  LDRRight = analogRead (LDRLeft_pin);
  LDRLeft = analogRead (LDRRight_pin);
  
  // Farrusco will seek for light if the motorSpeedLeft is assigned the LDR_Right
  motorLeftSpeed = map (LDRLeft, 0, 1023, 0, 255);
  motorRightSpeed = map (LDRRight, 0, 1023, 0, 255);
  
  DiffTurn(motorLeftSpeed, motorRightSpeed);
  } 
}
