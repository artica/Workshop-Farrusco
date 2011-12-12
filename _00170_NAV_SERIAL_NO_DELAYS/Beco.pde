// --------------------------------------------------------------------------- BECO VARS

int becoState;
int bumper = 0; // 1 = left, 2 = right

void Beco(int state) 
{
  if (state == 0) 
  {
    DiffTurn(-maxSpeedLeft, -maxSpeedRight);   
  }

  else if (state == 1) 
  {
    if (bumper == 1) // left
      DiffTurn(-maxSpeedLeft, maxSpeedRight);

    if (bumper == 2) // right
      DiffTurn(maxSpeedLeft, -maxSpeedRight);
  } 

  else if (state == 2) 
  {
    bumper = 0;
    if(isAssitedNavigation == 1)
      inByte = 'p';
  }
}

// resolves dead end
int checkDeadEnd()  

{ // check bumper status
  if (BLeft == 1) 
  {
    becoState = 0;
    becoMetro.interval(500);
    becoMetro.reset();
    bumper = 1;
  }
  else if (BRight == 1) 
  { 
    becoState = 0;
    becoMetro.interval(500);
    becoMetro.reset();
    bumper = 2;
  }
  else if ( (bumper != 0) && (becoMetro.check() == 1))
  {
    // no bumper is active, drive backwards was successfull - let's check timers to leave the dead end
    // becoState = 0 - turn    // becoState = 1 - back to begin
    if (becoState == 0) 
    {
      becoMetro.interval(500); 
      becoMetro.reset();
      becoState++;
    }
    else if (becoState == 1)
    {
      becoState++;
    }
  }
  if (bumper!=0) 
    Beco(becoState);
  return bumper;
}


