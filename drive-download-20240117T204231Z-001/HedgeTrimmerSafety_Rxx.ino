#include "Declarations.h"
#include "SensorBase.h"
#include "ResistiveSensor.h"
#include "CapacitiveSensor.h"

ResistiveSensor HandleSensor(A0, 1.5, 2.6, 200, 3);
CapacitiveSensor BladeSensor(10);

void setup() {
  Serial.begin(serialBaudrate);
  Serial.println("Serial available!");
  
  HandleSensor.Init();
  BladeSensor.Init();
}

void loop() {
  state = HandleSensor.State();
  BladeSensor.State();

  if (state != lastState)
  {
    stateChangeCount++;
    Serial.print("#"); Serial.print(stateChangeCount); Serial.print(": User is grabbing handles?: ");
    Serial.println((state) ? "Yes" : "No");
    lastState = state;
  }

}
