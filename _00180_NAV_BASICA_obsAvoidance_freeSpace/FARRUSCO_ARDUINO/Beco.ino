// --------------------------------------------------------------------------- BECO VARS

int becoState;
int bumper = 0; // 1 = left, 2 = right


// --------------------------------------------------------------------------- BECO
void Beco(int state) 
{
  if (state == 0) 
  {
    MotorDiffTurn(-MAX_VELOCITY, -MAX_VELOCITY);   
  }
  else if (state == 1) 
  {
    if (bumper == 1) // left
      MotorDiffTurn(MAX_VELOCITY, -MAX_VELOCITY);

    if (bumper == 2) // right
      MotorDiffTurn(-MAX_VELOCITY, MAX_VELOCITY);
  } 
  else if (state == 2) 
  {
    bumper = 0;
  }
}


// --------------------------------------------------------------------------- BECO SETUP
void checkDeadEndSetup()
{
  becoState = 2;
  bumper = 0;
}

// --------------------------------------------------------------------------- BECO UPDATE
/* 
  returns 'bumper': 
   1 if left bumper has been activated
   2 if right bumper has been activated
   0 dead end solved
*/
// resolves dead end
int checkDeadEndUpdate()  

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


