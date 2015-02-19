/*  ----------------------------------------------------------------------------
 *  WWW.GUIBOT.PT                                                  WWW.ARTICA.CC
 *  ----------------------------------------------------------------------------
 *  FARRUSCO COMPONENTS TESTER / CALIBRATOR
 *  ----------------------------------------------------------------------------
 *
 *  Interface visual para testar e calibrar os componentes do Farrusco
 *
 * 
 *  Visual Interface to test and calibrate Farrusco components   
 *
 *
 */

import processing.serial.*; 
Serial myPort;                  // The serial port
int serialState = 0;            // state var
int linefeed = 10;              // Linefeed in ASCII

PFont font;
PrintWriter output;

/* ************************************************************************************* 
 SETUP
 ************************************************************************************ */

void setup() {
  size(255, 600);
  
  font = loadFont("Verdana-10.vlw"); 
  textFont(font, 10); 

  State1Setup();

  State2Setup();
  
  frameRate(30);
}

/* *************************************************************************************
 DRAW
 ************************************************************************************ */

void draw() {

  background(0);

  if (serialState == 0) 
  {
    State1ButtonsUpdate();
  } 
  else  // if (serialState == 1) 
  {
    State2Update();
  }
  
  fill(255);  
  text(frameRate, 20, 590);
}

/* *************************************************************************************
  MOUSE FUNCTIONS
 ************************************************************************************ */

void mousePressed() 
{
  if (serialState == 0) 
  {
    serialState = (State1MousePressed()) ? 1:0;
  }

  if (serialState == 1) 
  { 
    State2MousePressed();
  }
}


void mouseReleased() 
{
  if (serialState == 0) 
  {
    State1ButtonsReleased();
  }
  if (serialState == 1) 
  { 
    State2ButtonsReleased();
  }
}

/* *************************************************************************************
 SERIAL FUNCTIONS
  ************************************************************************************ */
void serialEvent(Serial myPort) { 
  if (serialState == 1) 
  {
    // read the serial buffer:

    String myString = myPort.readStringUntil(linefeed);
    State2ControlParseFarruscoState(myString);
  }
}
