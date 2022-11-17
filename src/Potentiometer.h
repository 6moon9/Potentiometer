#include <Arduino.h>

class Potentiometer
{
    public:
        Potentiometer(uint8_t iPin, int iRest = 512, int iMargin = 50, bool iReversed = false);
        int getRawValue();
        int getValue();
        int lastValue;
        uint8_t pin;
        int rest = 512;
        int margin = 50;
        bool reversed = false;
};
