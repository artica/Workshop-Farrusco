void StopAndGo()
{
  if (IRValue > 299)
  { 
    DiffTurn(0, 0);
    delay(100);
  }
  else
  {
   DiffTurn(255, 255);
  }
}
