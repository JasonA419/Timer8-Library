
#include "Output8.h"
#include "Timer8.h"

Output8::Output8(outputnumber x, volatile uint8_t& ocrn, volatile uint8_t& ddrx, volatile uint8_t& port, uint8_t pin, Timer8& tc) : OutputNumber(x), OutputCompare(ocrn), DirectionRegister(ddrx), Port(port), Pin(pin), TC(tc)
{
  
}

void Output8::enable()
{
  DirectionRegister |= (1 << Pin);
}

void Output8::disable()
{
  DirectionRegister &= ~(1 << Pin);
}

void Output8::setValue(uint8_t value)
{
  OutputCompare = value;
}

uint8_t Output8::getValue()
{
  return OutputCompare;
}

void Output8::setMode(outputmode m)
{
  TC.RegisterA |= ((uint8_t)m << (6 - OutputNumber));
}

void Output8::enableInt()
{
  TC.IntMaskRegister |= (1 << (OutputNumber + 1));
}

void Output8::disableInt()
{
  TC.IntMaskRegister &= ~(1 << (OutputNumber + 1));
}

void Output8::clearFlag()
{
  TC.IntFlagRegister |= (1 << (OutputNumber + 1));
}
