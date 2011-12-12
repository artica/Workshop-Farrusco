int numSaves = 0;

boolean ProcessingSerialReciever() 
{
  
  boolean result = false;
  
  if(Serial.available()>0)
  {
    //digitalWrite(13, HIGH);
    result = true;
    
    // call the returned value from GetFromSerial() function
    switch(GetFromSerial())
    {

    case 'Z':  // servo
      ServoWrite(GetFromSerial());
      break;
    case 'P':  // pwm right
      MotorSetMaxVelocity(GetFromSerial(), GetFromSerial());
      break;
    case 'F':  // drive forward
      MotorDiffTurn(MAX_VELOCITY, MAX_VELOCITY);
      break;
    case 'B':   // drive backward
      MotorDiffTurn(-MAX_VELOCITY, -MAX_VELOCITY);
      break;
    case 'L':   // turn left
      MotorDiffTurn(-MAX_VELOCITY, MAX_VELOCITY);
      break;
    case 'R':  // turn right
      MotorDiffTurn(MAX_VELOCITY, -MAX_VELOCITY);
      break;
    case 'S':  // save on eeprom
      numSaves++;
      StoreEepromValues();
      break;
    case 'N':  // request state
      navState = GetFromSerial();
      break;
    case 'U':  // send serial data
      ProcessingSerialSender();
      break;
      

    default:   // H stop
      MotorDiffTurn(0, 0);
      break;  
    }
  }
  
  return result;
}

// read the serial port
byte GetFromSerial()
{
  while (Serial.available()<=0) {
  }
  return Serial.read();
}



void ProcessingSerialSender() 
{
  Serial.print(BLeft, DEC);
  Serial.print(",");
  Serial.print(BRight, DEC);
  Serial.print(",");
  Serial.print(IRValue, DEC);
  Serial.print(",");
  Serial.print(navState, DEC);
  Serial.print(",");
  Serial.print(maxSpeedLeft, DEC);
  Serial.print(",");
  Serial.print(maxSpeedRight, DEC);
  Serial.print(",");
  Serial.print(numSaves, DEC);
  Serial.println();
  
}

void StoreEepromValues()
{
  EEPROM.write(0,navState);
  EEPROM.write(1,maxSpeedLeft);
  EEPROM.write(2,maxSpeedRight);
}

unsigned long previousTime;
unsigned long processingStateTime = 4000;
boolean processingState = true;


int ProcessingUpdate() 
{
  unsigned long currentTime = millis();
  
  if (currentTime - previousTime > processingStateTime)
  {
    processingState = false;
    return processingState;
  }
  
  if (bumperMetro.check()) { 
    BumperReader();
  }

  if (sensorIRMetro.check()) { 
    ReadIR();
  }
  if(ProcessingSerialReciever()) {
    previousTime = currentTime;
    processingState = true;
  }
  
  return processingState;
  
}



