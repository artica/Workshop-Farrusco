

// --------------------------------------------------------------------------- UPDATE

void obstacleAvoidanceUpdate() 
{
  BumperReader();
  
  if (sensorIRMetro.check() == 1) { 
    ReadIR();
  }
  
  if (servoMetro.check() == 1) { 
    ServoRange(servoMin, servoMax, servoInc);
  }
  
  // 1 = left bumper // 2 = right bumper // 0 = clear
  if (!checkDeadEnd())  // THE SAME AS (checkDeadEnd() == 0)
  {  
    //Are we near an obstacle?
    if (IRValue >= 300)   
    {   
      if (servoPos < 90) 
      {
        Serial.println("if (servoPos < 90)");
        motorRightSpeed = maxSpeedRight;
        motorLeftSpeed = 0;
        
        // slow down servo speed and constrain range
        servoDel = 250;
        servoMin = 20;
        servoMax = 80;
      }
      else //if (servoPos > 90) 
      {
        Serial.println("if (servoPos > 90)");
        motorRightSpeed = 0;
        motorLeftSpeed = maxSpeedLeft;  
        
        // slow down servo speed and constrain range
        servoDel = 250;
        servoMin = 110;
        servoMax = 160;
      }
    }
    else// (IRValue < 299)
    {
        Serial.println("else");
        motorRightSpeed = maxSpeedRight;
        motorLeftSpeed = maxSpeedLeft;
        
        // speed up servo speed and maximize range
        servoDel = 45;
        servoMin = 20;
        servoMax = 160;
     }
    // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
    DiffTurn(motorLeftSpeed,motorRightSpeed);
  }
}


