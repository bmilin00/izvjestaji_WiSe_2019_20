#include "Sensors.h"
#include <LowPower.h>
 
SENSORS sensor;
 
typedef enum
{
  READ_SERIAL,
  READ_SENSORS,
  SLEEP,
  RADIO_COMM,
  NUM_STATES
} StateType;
 
void setup()
{
  Serial.begin(9600);
  sensor.DHT_init();
  sensor.BH1750_init();
  delay(100);
}
 
StateType state = READ_SERIAL;
 
void loop()
{
 
  switch (state)
  {
  case READ_SERIAL:
    state = READ_SENSORS;
    break;
  case READ_SENSORS:
    sensor.readTempHum();
    sensor.readLight();
    state = RADIO_COMM;
    break;
  case RADIO_COMM:
    state = SLEEP;
    break;
  case SLEEP:
    delay(50);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    delay(50);
    state = READ_SERIAL;
    break;
  }
}