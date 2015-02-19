

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
void State2ControlParseFarruscoState(String myString)
{

    // if you got any bytes other than the linefeed:
    if (myString != null) 
    {
      myString = trim(myString);
      //println(myString);
      // split the string at the commas
      // and convert the sections into integers:
      int farruscoState[] = int(split(myString, ','));

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
void State2MousePressed()
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
void State2ButtonsReleased() 
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
void State2ButtonsUpdate() 
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
void State2DistanceSensorUpdate()
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
void State2UpdaterValues() 
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

void State2Setup()
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


void State2Update()
{
  sv1.render();
  sv2.render();
  sh1.render();
  State2ButtonsUpdate();
  
  State2DistanceSensorUpdate();
  
  State2UpdaterValues();
}


