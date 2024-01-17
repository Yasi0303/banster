class ResistiveSensor : protected SensorBase {
  protected:
  int sensorPin;

  float chargeVoltage = 3.7;
  
  double lastMeas;
  unsigned long lastMeasTime;
  unsigned long measTime;

  double maxVal;
  double minVal;

  void MeasureSensor()
  {
    measTime = micros();
    meas = double(analogRead(sensorPin))/1023.0*5.0;
  }

  bool RCVoltageCheck()
  {
    maxVal = (lastMeas - chargeVoltage)*exp(-(double(measTime - lastMeasTime))/800.0) + chargeVoltage;
    minVal = lastMeas*exp(-(double(measTime - lastMeasTime))/800.0);


    if (meas < 0.3 || meas > chargeVoltage - 0.3)
    {
      if (abs(maxVal - meas) < 0.005 || abs(meas - minVal) < 0.005)
      {
        return true;
      }
    }


    if (meas > minVal && meas < maxVal)
    {
      return true;
    }
    
    return false;
  }

  void CheckReliability()
  {
    int unusableCount = 0;
  
    while (!RCVoltageCheck())
    {
      unusableCount++;
      if (unusableCount >= maxNofUnusableData)
      {
        EmergencyStop("Measurements not as expected.");
      }
      
      MeasureSensor();
    }
    
    lastMeasTime = measTime;
    lastMeas = meas;
  }
  
  public:
  ResistiveSensor(int sensorPin,double lowerThreshold, double upperThreshold,
                  unsigned int verificationTime, unsigned int maxNofUnusableData)
  {
    this->sensorPin = sensorPin;
    this->lowerThreshold = lowerThreshold;
    this->upperThreshold = upperThreshold;
    this->verificationTime = verificationTime;
    this->maxNofUnusableData = maxNofUnusableData;
  }

  void Init()
  {
    MeasureSensor();
    lastMeas = meas;
    lastMeasTime = measTime;
  }

  
  bool State()
  {
    bool result = true;

    MeasureSensor();
    CheckReliability();
    result &= SchmittTrigger();
    result &= Verification(result);
    return result;
  }
};
