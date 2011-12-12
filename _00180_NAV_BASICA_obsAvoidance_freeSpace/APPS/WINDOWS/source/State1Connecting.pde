/* *************************************************************************************
 
 
 Serial Initializer
 
 
 ************************************************************************************ */

Button[] serialButtons = new Button[33];
int totalSerialButtons;

boolean State1MousePressed()
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

void State1Setup()
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
void State1ButtonsUpdate() 
{  

  text("Select Serial Port", 20, 50);

  for (int i=0; i < Serial.list().length; i++) 
  {
    serialButtons[i].update();
    serialButtons[i].display();
  }
}


void State1ButtonsReleased() 
{
  for (int i=0; i <= totalSerialButtons; i++) 
  {
    serialButtons[i].release();
  }
}

