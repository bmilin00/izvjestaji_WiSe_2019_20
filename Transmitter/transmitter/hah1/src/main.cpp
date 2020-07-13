#include <Arduino.h>
#include <LowPower.h>
#include "main.h"
#include "Sensors.h"
#include "Radio_nRF.h"

SENSORS sensor;

RADIO radioNRF;

SensorData dataToSend;
StateType state = READ_SERIAL;

void setup()
{
  Serial.begin(9600);
  radioNRF.nRF_init();
  sensor.vl53l0x_init();
}

void loop()
{
  Serial.println("S");
  switch (state)
  {
  case READ_SERIAL:

    state = READ_SENSORS;
    break;

  case READ_SENSORS:
    dataToSend.dist = sensor.readDistance();
    state = RADIO_TX;
    break;

  case RADIO_TX:
    radioNRF.RF_send(dataToSend);

    state = SLEEP;
    break;

  case SLEEP:

    delay(50);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
    delay(50);

    state = READ_SERIAL;
    break;

  default:
    break;
  }
}
