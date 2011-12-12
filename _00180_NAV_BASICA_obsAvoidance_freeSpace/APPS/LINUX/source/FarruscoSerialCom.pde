
void SerialSelector(String port) 
{
  //println(Serial.list()); // List COM-ports
  // Open the port that the board is connected to and use the same speed (9600 bps)
  myPort = new Serial(this, port, 115200);

  //println(Serial.list().length);
  // read bytes into a buffer until you get a linefeed (ASCII 10):
  myPort.bufferUntil(linefeed);

}

//char caracter2Send;

void SerialSavePreset()
{
  myPort.write('S');
  
}
void SerialWriteNavigation(int naveState) 
{
  myPort.write('N');
  myPort.write(naveState);
}

void SerialWriteServo(int pos)
{
  myPort.write('Z');
  myPort.write(pos);
}
void SerialWriteMotors(int left, int right)
{
    myPort.write('P');
    myPort.write(left);
    myPort.write(right);
}


void SerialWriteForward()
{
    myPort.write('F');
}
void SerialWriteBackward()
{
    myPort.write('B');
}
void SerialWriteLeft()
{
    myPort.write('L');
}
void SerialWriteRight()
{
  myPort.write('R');
}
void SerialWriteStop()
{
  myPort.write('H');
}


void SerialWriteRequestState() 
{
  myPort.write('U');
}

/*
Generic Serial event from serial component openend 

void serialEvent(Serial myPort) { 
  if (serialState == 1) 
  {
    // read the serial buffer:

    String myString = myPort.readStringUntil(linefeed);

    // if you got any bytes other than the linefeed:
    if (myString != null) 
    {
      myString = trim(myString);
      //println(myString);
      // split the string at the commas
      // and convert the sections into integers:
      int farruscoState[] = int(split(myString, ','));

      //assign the values you got to variables:
      bumperLeft = farruscoState[0];
      bumperRight = farruscoState[1];
      distanceSensor = farruscoState[2];
      naveState = farruscoState[3];
      sv1.render(sliderPos[1] = farruscoState[4]);
      sv2.render(sliderPos[2] = farruscoState[5]);
      
      //servoAngle = sensors[3];
      println(farruscoState[6]);
    }
  }
}
 */




