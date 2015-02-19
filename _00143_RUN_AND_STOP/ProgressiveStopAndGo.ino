void ProgressiveStopAndGo()
{
  if (IRValue > 299)
  { 
    DiffTurn(0, 0);
    delay(100);
  }
  else
  {
    mappedValue = map(IRValue, 300, 0, 0, 255); 
    DiffTurn(mappedValue, mappedValue);
  }
}

