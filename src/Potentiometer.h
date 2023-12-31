#include <Arduino.h>

class Potentiometer
{
    public:
        Potentiometer(uint8_t iPin, bool iReversed = false, int iRest = 512, int iMargin = 50, int iToMin = -1023, int iToMax = 1023);
        int getRawValue();
        int getValue();
        int lastValue;
        uint8_t pin;
        int rest = 512;
        int margin = 50;
        bool reversed = false;
        int toMin = -1023;
        int toMax = 1023;
};
