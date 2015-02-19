

// --------------------------------------------------------------------------- UPDATE

void obstacleAvoidanceUpdate() 
{
  BumperReader();
  
  if (sensorIRMetro.check() == 1) { 
    ReadIR();
    sensorIRMetro.reset();
  }

  ServoRange(servoMin, servoMax, servoInc);
  
  // 1 = left bumper // 2 = right bumper // 0 = clear
  if (!checkDeadEnd())  // THE SAME AS (checkDeadEnd() == 0)
  {  
    motorRightSpeed = maxSpeedRight;
    motorLeftSpeed = maxSpeedLeft;
    
    // speed up servo speed and maximize range
    servoDel = 45;
    servoMin = 20;
    servoMax = 160;
    //Are we near an obstacle?
    if (IRValue >= 300)   
    {   
      if (servoPos < 90) 
      {
        Serial.println("if (servoPos < 90)");
        motorRightSpeed = 0;
        
        // slow down servo speed and constrain range
        servoDel = 250;
        servoMin = 20;
        servoMax = 80;
      }
      else //if (servoPos > 90) 
      {
        Serial.println("if (servoPos > 90)");
        motorLeftSpeed = 0;
        
        // slow down servo speed and constrain range
        servoDel = 250;
        servoMin = 110;
        servoMax = 160;
      }
    }

    // chamada da função 'DiffTurn' atribuindo sempre os valores de rotação dos motores
    DiffTurn(motorLeftSpeed,motorRightSpeed);
  }
}


