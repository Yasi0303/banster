#include <FreqCount.h>

class CapacitiveSensor : protected SensorBase {
  protected:
  
  public:
  unsigned long FreqCountTime;

  CapacitiveSensor(unsigned long FreqCountTime)
  {
    this->FreqCountTime = FreqCountTime;
  }

  void Init()
  {
    FreqCount.begin(FreqCountTime);
  }

  bool State()
  {
    if (FreqCount.available()) { meas = FreqCount.read(); }
    
    bool result = true;

    
    result &= SchmittTrigger();
    result &= Verification(result);
    return result;
    
  }
  
};
