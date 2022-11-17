#include <Arduino.h>

#include "Potentiometer.h"

/**
 * Setup the potentiometer
 */
Potentiometer::Potentiometer(uint8_t iPin, int iRest = 512, int iMargin = 50, bool iReversed = false)
{
    pin = iPin;
    rest = iRest;
    margin = iMargin;
    reversed = iReversed;
    pinMode(pin, INPUT);
}

/**
 * Get the raw value of readed on the potentiometer's pin
 * 
 * @return int the analog value of `Potentiometer::pin`
 */
int Potentiometer::getRawValue()
{
    return analogRead(pin);
}

/**
 * Get the value of the potentiometer after treatment
 * 
 * @return int -1 if the potentiometer is in rest position (the raw value is between `rest - margin` and `rest + margin`) ; -3 if the potentiometer is in a fullback position (the raw value is less than `0 + margin`) ; -2 if the potentiometer is in a fullforward position (the raw value is more than `1023 - margin`) ; the raw value of the potentiometer else
 */
int Potentiometer::getValue()
{
    int rawValue = getRawValue();
    if (reversed)
        rawValue -= rawValue * 2;
    int finalValue;
    if (rawValue < (rest + margin) && rawValue > (rest - margin))
        finalValue = -1;
    else if (rawValue < (0 + margin))
        finalValue = -3;
    else if (rawValue > (1023 - margin))
        finalValue = -2;
    else
        finalValue = rawValue;
    lastValue = finalValue;
    return finalValue;
}
