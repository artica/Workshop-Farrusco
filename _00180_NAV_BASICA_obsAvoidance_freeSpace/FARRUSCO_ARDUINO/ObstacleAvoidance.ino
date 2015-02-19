// --------------------------------------------------------------------------- SETUP



void obstacleAvoidanceSetup()
{
  checkDeadEndSetup();
  
}



// --------------------------------------------------------------------------- BUMPERS

void BumperReader() 
{
  BLeft = digitalRead(bumperLeft);
  BRight = digitalRead(bumperRight);
}

// --------------------------------------------------------------------------- UPDATE
int freeSpaceState = 0;
int freeSpaceLeft = 0;
int freeSpaceRight = 0;

void FreeSpaceUpdate() 
{
  BumperReader();
  
  if (sensorIRMetro.check() == 1) { 
    ReadIR();
  }
  
  if (sensorIRMetro.check() == 1){ 
    ServoRange(80, 100);
  }
  // 1 = left bumper // 2 = right bumper // 0 = clear
  if (!checkDeadEndUpdate())  // (checkDeadEnd() == 0)
  {  
    
    //We are near an obstacle?
    if (IRValue >= 300)   
    {   

      MotorDiffTurn(maxSpeedLeft/4,maxSpeedRight/4);
      ServoWrite(150);
      delay(250);
      freeSpaceRight =ReadIR();
      ServoWrite(20);
      delay(250);
      freeSpaceLeft = ReadIR();
      
      if (freeSpaceLeft<freeSpaceRight)
        MotorDiffTurn(0, MAX_VELOCITY);
      else
        MotorDiffTurn(MAX_VELOCITY, 0);
      delay(250);
    }
    else// (IRValue < 299)
    {
        MotorDiffTurn(MAX_VELOCITY, MAX_VELOCITY);
        ServoSetInterval(50, 50, 120);
     }
  }
}

// --------------------------------------------------------------------------- UPDATE
void ObstacleAvoidanceUpdate() 
{
  BumperReader();
  
  if (sensorIRMetro.check() == 1) { 
    ReadIR();
  }
  
  if (servoMetro.check() == 1) { 
    ServoRange();
  }
  
  // 1 = left bumper // 2 = right bumper // 0 = clear
  if (!checkDeadEndUpdate())  // (checkDeadEnd() == 0)
  {  
    //We are near an obstacle?
    if (IRValue >= 300)   
    {   
      if (ServoGetPos() < 90) 
      {
        MotorDiffTurn(MAX_VELOCITY, 0);
        ServoSetInterval(250, 20, 80);
      }
      else //if (servoPos > 90) 
      {
        MotorDiffTurn(0, MAX_VELOCITY);
        ServoSetInterval(250, 110, 170);
      }
    }
    else// (IRValue < 299)
    {
        MotorDiffTurn(MAX_VELOCITY, MAX_VELOCITY);
        ServoSetInterval(50, 50, 120);
     }
  }
}


