void AssistedNavigation()
{
  BumperReader(); 
  if(!checkDeadEnd())
        SerialAnalyze(); 
}

int SerialAnalyze()
{
  //d
  if (inByte=='d' || inByte == 'D')
  {
    DiffTurn(maxSpeedLeft, -maxSpeedRight);   
  }
  //a
  else if(inByte=='a'|| inByte=='A')
  {
    DiffTurn(-maxSpeedLeft, maxSpeedRight);;
  }
  //s
  else if(inByte=='s'|| inByte=='S')
  {
    DiffTurn(-maxSpeedLeft, -maxSpeedRight);
  }
  //w
  else if(inByte=='w'|| inByte=='W')
  {
    DiffTurn(maxSpeedLeft, maxSpeedRight);
  }
  //p
  else if(inByte=='p'|| inByte=='P' || inByte=='G' || inByte=='g')
  {
    DiffTurn(0, 0);
  }
}
