import processing.core.*; 
import processing.xml.*; 

import processing.serial.*; 

import java.applet.*; 
import java.awt.Dimension; 
import java.awt.Frame; 
import java.awt.event.MouseEvent; 
import java.awt.event.KeyEvent; 
import java.awt.event.FocusEvent; 
import java.awt.Image; 
import java.io.*; 
import java.net.*; 
import java.text.*; 
import java.util.*; 
import java.util.zip.*; 
import java.util.regex.*; 

public class FARRUSCO_PROCESSING extends PApplet {

/*  ----------------------------------------------------------------------------
 *  WWW.GUIBOT.PT                                                  WWW.ARTICA.CC
 *  ----------------------------------------------------------------------------
 *  FARRUSCO COMPONENTS TESTER / CALIBRATER
 *  ----------------------------------------------------------------------------
 *
 *  Interface visual para testar e calibrar os componentes do Farrusco
 *
 * 
 *  Visual Interface to test and calibrate Farrusco components   
 *
 *
 */

 
Serial myPort;                  // The serial port
int serialState = 0;            // state var
int linefeed = 10;              // Linefeed in ASCII

PFont font;
PrintWriter output;

/* ************************************************************************************* 
 SETUP
 ************************************************************************************ */

public void setup() {
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

public void draw() {

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

public void mousePressed() 
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


public void mouseReleased() 
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
public void serialEvent(Serial myPort) { 
  if (serialState == 1) 
  {
    // read the serial buffer:

    String myString = myPort.readStringUntil(linefeed);
    State2ControlParseFarruscoState(myString);
  }
}
class Button {
  int x, y; // The x- and y-coordinates
  int sizeX, sizeY; // Dimension (width and height)
  int baseGray; // Default gray value
  int overGray; // Value when mouse is over the button
  int pressGray; // Value when mouse is over and pressed
  boolean over = false; // True when the mouse is over
  boolean pressed = false; // True when the mouse is over and pressed
  boolean ignoreClick = false;
  String st;


  Button(int xp, int yp, int sx, int sy, int b, int o, int p, String _st, boolean _ignoreClick) {
    x = xp;
    y = yp;
    sizeX = sx;
    sizeY = sy;
    baseGray = b;
    overGray = o;
    pressGray = p;
    st = _st;
    ignoreClick = _ignoreClick;
  }


  // Updates the over field every frame
  public void update() 
  {
    if ((mouseX >= x) && (mouseX <= x+sizeX) && (mouseY >= y) && (mouseY <= y+sizeY)) {
      over = true;
    } 
    else {
      over = false;
    }
  }


  public boolean press() 
  {
    if (over == true) {
      pressed = true;
      return true;
    } 
    else {
      return false;
    }
  }



  public void release() 
  {
    pressed = false; // Set to false when the mouse is released
  }

  public void display() 
  {
    if (ignoreClick) {

      if (pressed == true) {
        fill(pressGray);
      } 
      else if (over == true) {
        fill(overGray);
      }
      else {
        fill(baseGray);
      }
    }

    else {
      if (pressed == true) {
        fill(pressGray);
      } 
      else { 
        fill(baseGray);
      }
    }
    stroke(255);
    rectMode(CORNER);
    rect(x, y, sizeX, sizeY);

    fill(255);
    text(st, x+10, y+sizeY/2+5);
  }
}


public void SerialSelector(String port) 
{
  //println(Serial.list()); // List COM-ports
  // Open the port that the board is connected to and use the same speed (9600 bps)
  myPort = new Serial(this, port, 115200);

  //println(Serial.list().length);
  // read bytes into a buffer until you get a linefeed (ASCII 10):
  myPort.bufferUntil(linefeed);

}

//char caracter2Send;

public void SerialSavePreset()
{
  myPort.write('S');
  
}
public void SerialWriteNavigation(int naveState) 
{
  myPort.write('N');
  myPort.write(naveState);
}

public void SerialWriteServo(int pos)
{
  myPort.write('Z');
  myPort.write(pos);
}
public void SerialWriteMotors(int left, int right)
{
    myPort.write('P');
    myPort.write(left);
    myPort.write(right);
}


public void SerialWriteForward()
{
    myPort.write('F');
}
public void SerialWriteBackward()
{
    myPort.write('B');
}
public void SerialWriteLeft()
{
    myPort.write('L');
}
public void SerialWriteRight()
{
  myPort.write('R');
}
public void SerialWriteStop()
{
  myPort.write('H');
}


public void SerialWriteRequestState() 
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




/* *************************************************************************************
 
 
 Serial Initializer
 
 
 ************************************************************************************ */

Button[] serialButtons = new Button[33];
int totalSerialButtons;

public boolean State1MousePressed()
{
  boolean result = false;
  for (int i=0; i <= totalSerialButtons; i++) 
  {
    if (serialButtons[i].press() == true)
    {
      serialButtons[i].press();
      SerialSelector(Serial.list()[i]);
      result = true;
      break;
    }
  }
  return result;
}

public void State1Setup()
{
  int ypos = 75;

  // populate buttons with serial ports available  
  for (int i=0; i<Serial.list().length; i++) {
    String myString = Integer.toString(i)+"  "+Serial.list()[i];
    serialButtons[i] = new Button (20, ypos, 200, 20, color(0), color(100), color(200), myString, true);
    totalSerialButtons = i;
    ypos+=20;
  }
}
public void State1ButtonsUpdate() 
{  

  text("Select Serial Port", 20, 50);

  for (int i=0; i < Serial.list().length; i++) 
  {
    serialButtons[i].update();
    serialButtons[i].display();
  }
}


public void State1ButtonsReleased() 
{
  for (int i=0; i <= totalSerialButtons; i++) 
  {
    serialButtons[i].release();
  }
}



/* *************************************************************************************
 BUTTONS
 ************************************************************************************ */

int numButtons = 4;
Button[] button = new Button[numButtons];

Button bumperSquareLeft, bumperSquareRight;

Button[] naveMode = new Button[2];

int naveState;
String[] NavegationModeDesc = {"   Obstacle Avoid","   FreeSpace"};

Button saveButton;

/* *************************************************************************************
 Sliders
 ************************************************************************************ */
sliderV sv1, sv2;

sliderH sh1;

/* *************************************************************************************
 VALUES COMING FROM THE SERIAL PORT / ARDUINO
 ************************************************************************************ */

int bumperLeft, bumperRight, distanceSensor, servoAngle, sensor4;

float previousTime;
float serialUpdateTime = 50;

/* *************************************************************************************
 Parse State from arduino
 ************************************************************************************ */
public void State2ControlParseFarruscoState(String myString)
{

    // if you got any bytes other than the linefeed:
    if (myString != null) 
    {
      myString = trim(myString);
      //println(myString);
      // split the string at the commas
      // and convert the sections into integers:
      int farruscoState[] = PApplet.parseInt(split(myString, ','));

      //assign the values you got to variables:
      bumperSquareLeft.pressed = (farruscoState[0] == 0) ? false:true;
      bumperSquareRight.pressed = (farruscoState[1] == 0) ? false:true;
      
      distanceSensor = farruscoState[2];
      naveState = farruscoState[3];
      
      // 
      for(int i =0; i< 2; i++)
      {
        naveMode[i].pressed = (i==naveState) ?true:false;
      }
      
      sv1.render(farruscoState[4]);
      sv2.render(farruscoState[5]);
      
      //servoAngle = sensors[3];

      //DEBUG SAVE TIMES
      //println(farruscoState[6]);
    }
}

/* *************************************************************************************
 BUTTONS CONTROL  
 ************************************************************************************ */
public void State2MousePressed()
{
  
  // movememnt buttons
  for (int i=0; i < numButtons; i++) 
  {
    if (button[i].press() == true)
    {
      button[i].press();
      switch (i) 
      {
        case 0:
          SerialWriteForward();
          break;
        case 1:
          SerialWriteBackward();
          break;
        case 2:
          SerialWriteLeft();
          break;
        case 3:
          SerialWriteRight();
          break;        
      }
    }
  }
  
  // navigation buttons
  for (int i=0; i<2; i++)
  {
    if((naveMode[i].over) && (!naveMode[i].pressed))
    {
      naveMode[i].pressed = true;
      SerialWriteNavigation(i);
    }
  }
  
  // save button
  if((saveButton.over) && (!saveButton.pressed))
  {
    //saveButton.pressed = true;
    SerialSavePreset();
    saveButton.press();
  }
}


// movement buttons released
public void State2ButtonsReleased() 
{
  // movement buttons
  for (int i=0; i < numButtons; i++) 
  {
    if (button[i].pressed == true)
      button[i].release();
  }
  
  SerialWriteStop();
  
  // save button
  saveButton.release();
}



/* *************************************************************************************
 UPDATERS
 Update component for the visual buttons
 ************************************************************************************ */
public void State2ButtonsUpdate() 
{
  fill(255);
  text("BUMPERS", 100, 38);
  
  fill(255, 120);
  text("servo position", 155, 247);
  
  fill(255);
  text("MOTORS CONTROL", 80, 295);
  
  text("PWM", 20, 295);
  text("PWM", 209, 295);
  
  // BUMPERS
  bumperSquareLeft.update();
  bumperSquareLeft.display();

  bumperSquareRight.update();
  bumperSquareRight.display();
  
  // MOVEMENT & DRIVE BUTTONS
  for (int i=0; i < numButtons; i++) 
  {
    button[i].update();
    button[i].display();
  }
  
  // NAVIGATION MODE BUTTONS
  for (int i=0; i< 2; i++)
  {
    naveMode[i].update();
    naveMode[i].display();
  }
  
  // SAVE
  saveButton.update();
  saveButton.display();

}


/* *************************************************************************************
 DistanceSensor
 This function will update the visual component of distance sensor
 ************************************************************************************ */
public void State2DistanceSensorUpdate()
{
  fill(255);
  text("Distance Sensor ", 35, 220);
  text(distanceSensor, 120, 221);
  
  fill(100, 50);
  rect(25, 207, distanceSensor/3, 15);
}


/* *************************************************************************************
 UPDATES COMUNICATIONS BY REQUESTING FROM TIME TO TIME THE STATE/NAVIGATION MODE, 
 SENDS MOTORS AND SERVO VALUES FROM TIME TO TIME WHEN GUI IS CHANGING THEM
 ************************************************************************************ */
public void State2UpdaterValues() 
{
  float currentTime = millis();
  if (currentTime - previousTime > serialUpdateTime) 
  {
    if ((sv1.dragging)||(sv2.dragging))
    {
      SerialWriteMotors(sv1.result,sv2.result);
    }
    if (sh1.dragging)
    {
      SerialWriteServo(sh1.result);
    }
    previousTime = currentTime;
    SerialWriteRequestState();
  }
}


/* *************************************************************************************
 SETUP
 PREPARES THE GUI AND STATE VARS 
 ************************************************************************************ */

public void State2Setup()
{
  
  // BUMPERS
  bumperSquareLeft = new Button(25, 45, 100, 100, color(0), color(100), color(200), "LEFT", false);
  bumperSquareRight = new Button(125, 45, 100, 100, color(0), color(100), color(200), "RIGHT", false);
  
  // SERVO ANGLE SLIDER
  sh1 = new sliderH (25, 235, 200, 15, color(255), 90, 10, 170);
  
  // MOVEMENT & DRIVE BUTTONS
  button[0] = new Button (100, 305, 50, 50, color(0), color(100), color(200), "F", true);
  button[1] = new Button (100, 415, 50, 50, color(0), color(100), color(200), "B", true);
  button[2] = new Button (50, 360, 50, 50, color(0), color(100), color(200), "L", true);
  button[3] = new Button (150, 360, 50, 50, color(0), color(100), color(200), "R", true);
  
  // MOTOR PWM SLIDERS
  sv1 = new sliderV (20, 305, 23, 160, color(255), 50, 0, 255);
  sv2 = new sliderV (210, 305, 23, 160, color(255), 50, 0, 255);
  
  // NAVIGATION BUTTONS
  for (int i=0; i< 2; i++)
    naveMode[i]= new Button ( 25, 520+(20*i), 10, 10, color(0), color(100), color(200), NavegationModeDesc[i], true);

  // SAVEBUTTON
  saveButton = new Button(185, 565, 50, 20, color(0), color(100), color(200), "SAVE", true);
}


/* *************************************************************************************
 UPDATE
 UPDATES THE STATE, BY CHECKING THE GUI AND UPDATING THE COMUNICATION
 ************************************************************************************ */


public void State2Update()
{
  sv1.render();
  sv2.render();
  sh1.render();
  State2ButtonsUpdate();
  
  State2DistanceSensorUpdate();
  
  State2UpdaterValues();
}


/* Slider Class - www.anthonymattox.com */
/* adapted by - www.guilhermemartins.net */

class sliderH {
  int x, y, w, h;
  float p, fp; // fp : final pos - the pos we want to know
  boolean slide;
  int c, cb;
  float minval, maxval;
  int result;
  boolean dragging;
  /*
  
   x : x
   y : y
   s : size
   col : color
   start : start value
   _min : min value to be mapped
   _max : max value to be mapped
   _interp : interpolate true or false
   _filtro : interp filter
   
   */

  sliderH (int _x, int _y, int _w, int _h, int col, float _start, float _min, float _max) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    slide = true;
    c = col;
    minval = _min;
    maxval = _max;
    p = map(_start, minval, maxval, x, x+w);
    fp = map(p, x, x+w, minval, maxval);
    cb = color(red(c),green(c),blue(c));
    dragging = false;
  }

  public void render() {

    noStroke();
    fill(200, 50);
    rect(x, y, w+5, h+1);

    noStroke();
    fill(cb);
    rect(p, y, 2, h);

    result = (int)fp;
    
    fill(180);
    text(result, x, y+h-1);
    dragging = false;
    if (slide=true && mousePressed==true && mouseY>y && mouseY<y+h){
      dragging = true;
      if ((mouseX<=x+w) && (mouseX>=x)) {

          p = mouseX;
          fp = map(p, x, x+w, minval, maxval);
        
        if (p<0) {
          p=0;
        } 
        else if (p>x+w) {
          p=x+w;
        }
      }
    }
  }
  
  
}


/* Slider Class - www.anthonymattox.com */
/* adapted by - www.guilhermemartins.net */


/* Slider Class - www.anthonymattox.com */
/* adapted by - www.guilhermemartins.net */

class sliderV {
  int x, y, w, h;
  float p, pp;
  //float filtro = 0.1;
  boolean slide;
  int c, cb;
  float filtro;
  int result;
  int minval, maxval;
  boolean dragging;
 
//  _x : xpos
//  _y : ypos
//  _w : width
//  _h : height
//  _col : color
//  _start : start position

 
  
  
  sliderV (int _x, int _y, int _w, int _h, int _col, float _start, int _min, int _max) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    p = _start;
    slide = true;
    c = _col;
    cb = color(red(c),green(c),blue(c));
    minval = _min;
    maxval = _max;
    dragging = false;
  }

  public void render() {

    noStroke();
    fill(200, 50);
    rect(x, y, w, h);

    noStroke();
    fill(cb);
    rect(x, h-p+y, w, 14);
    
//    fill(255);
//    text(round(p), x+(w/2)-13, y-6);

    result = (int)map(round(p), 0, h, minval, maxval);
    
    fill(0);
    text(result, x+1, h-p+y+10);
    dragging = false;
    if (slide=true && mousePressed==true && mouseX<x+25 && mouseX>x){
      
      if ((mouseY<=y+h) && (mouseY>=y)) {
        dragging = true;
        p = h-(mouseY-y); //p + (h-(mouseY-y));
      
        if (p<0) {
          p=0;
        } 
        else if (p>h) {
          p=h;
        }
      }
    }
  }
  
  
  
  public void render(int sliderPos) {
    
    //sliderPos = _sliderPos;

    noStroke();
    fill(200, 50);
    rect(x-1, y-4, w, h+10);

    noStroke();
    fill(cb);
    rect(x, h-p+y-5, w, 13);
    fill(c);
    rect(x+2, h-p+y-5, w-5, 13);
    fill(0);
    text(round(p), x+2, h-p+y+6);
    if(result!= sliderPos)
      p = map (sliderPos, minval, maxval,0,h);// + (h-(sliderPos-y));
  
  }
}


/*
class sliderV {
  int x, y, w, h;
  float p, fp; // fp : final pos - the pos we want to know
  //float filtro = 0.1;
  boolean slide;
  color c, cb;
  float filtro;
  int minval, maxval;
  int result;
  
  // _x : xpos
  // _y : ypos
  // _w : width
  // _h : height
  // _col : color
  //_start : start position
  
  
  
  
  sliderV (int _x, int _y, int _w, int _h, color _col, float _start, int _min, int _max) {
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    p = _start;
    slide = true;
    c = _col;
    cb = color(red(c),green(c),blue(c),150);
    minval = _min;
    maxval = _max;
    
    fp = map(p, x, x+w, minval, maxval);
  }

  void render() {

    noStroke();
    fill(200, 50);
    rect(x-1, y-4, w, h+10);

    noStroke();    
    fill(cb);
    rect(x, h-p+y-5, w-1, 13);
    
    result = (int)map(round(p), 0, h, minval, maxval);
    
    fill(0);
    text(result, x+1, h-p+y+6);

    if (slide=true && mousePressed==true && mouseX<x+w && mouseX>x){
      if ((mouseY<=y+h+10) && (mouseY>=y-5)) {
        
        p = h-(mouseY-y);
        
        if (p<0) {
          p=0;
        } 
        else if (p>h) {
          p=h;
        }
      }
    }
  }
}
*/




  static public void main(String args[]) {
    PApplet.main(new String[] { "--bgcolor=#FFFFFF", "FARRUSCO_PROCESSING" });
  }
}
