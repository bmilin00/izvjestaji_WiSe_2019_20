#include "Sensors.h"
VL53L0X distsenzor;

SENSORS::SENSORS() {}
SENSORS::~SENSORS() {}

void SENSORS::vl53l0x_init(){

if (!distsenzor.init())
{
    Serial.println("Failed to detect and initialize sensor!");
    while (1) {}
  }

  distsenzor.startContinuous();
}

int SENSORS::readDistance()
{
  int distance = distsenzor.readRangeContinuousMillimeters();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("mm");
  if (distsenzor.timeoutOccurred())
  {
    Serial.print(" TIMEOUT");
  }
   Serial.println();
  return distance;
}
