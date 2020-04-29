#include "Sensors.h"

SENSORS sensor;

void setup() {
  Serial.begin(9600);
  sensor.DHT_init();
  sensor.BH1750_init();
}

void loop() {
  sensor.readTempHum();
  sensor.readLight();
}
