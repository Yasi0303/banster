class SensorBase {
  public:
  
  unsigned int maxNofUnusableData;
  double upperThreshold;
  double lowerThreshold;
  unsigned int verificationTime;
  double meas;

  
  protected:

  bool lastSchmittState = false;
  unsigned long lastTime = 0;
  

  public:
  
  void EmergencyStop(String reason = "")
  {
    Serial.println();
    Serial.println("#############################");
    Serial.println("Error! " + reason);
    Serial.println("Emergency stop!");
    Serial.println("#############################");
    
    while (true) // While forever.
    {
      // Do nothing.
    }
  }

  bool SchmittTrigger()
  {
    if (meas >= upperThreshold || (lastState && meas >= lowerThreshold))
    {
      lastSchmittState = true;
      return true;
    }

    lastSchmittState = false;
    return false;
  }

  bool Verification(bool inputState)
  { 
    if (inputState && lastTime == 0) { lastTime = millis(); }
    if (!inputState) { lastTime = 0; }
    if (inputState && millis() - lastTime >= verificationTime) { return true; }
    
    return false;
  }
};
