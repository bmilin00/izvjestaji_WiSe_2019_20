#ifndef Sensors_h
#define Sensors_h

#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <VL53L0X.h>

#define DHTPIN 3
#define DHTTYPE DHT22

class SENSORS
{
public:
        SENSORS();
        ~SENSORS();
        void vl53l0x_init();
        int readDistance();

};

#endif