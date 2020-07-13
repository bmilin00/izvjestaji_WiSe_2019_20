#ifndef main_h
#define main_h

// Payload that child sends to the parent
struct SensorData
{
    float dist;
};

typedef enum
{
    READ_SERIAL,
    READ_SENSORS,
    RADIO_TX,
    SLEEP,
} StateType;

#endif