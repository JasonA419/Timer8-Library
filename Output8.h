#ifndef Output8_h
#define Output8_h

#include "Arduino.h"

class Timer8;

class Output8
{
  
  public:
  enum outputnumber : uint8_t   // enumerator to limit input to valid range of inputs on 8-bit timers
  {
    OUTPUT_A = 0,
    OUTPUT_B = 1
  };
  
  enum outputmode : uint8_t
  {
    NORMAL = 0,
    TOGGLE = 1,
    CLEAR = 2,
    SET = 3,
    NONINVERTING = 2,
    INVERTING = 3
  };
  
  Output8(outputnumber x, volatile uint8_t& ocrn, volatile uint8_t& ddrx, volatile uint8_t& port, uint8_t pin, Timer8& tc);
  void enable();
  void disable();
  void setValue(uint8_t value);
  uint8_t getValue();
  void enableInt();
  void disableInt();
  void clearFlag();
  void setMode(outputmode m);
  boolean is16Bit() {return false;};
  boolean is8Bit() {return true;};

  protected:
  uint8_t OutputNumber;
  volatile uint8_t& OutputCompare;
  volatile uint8_t& DirectionRegister;
  volatile uint8_t& Port;
  uint8_t Pin;
  Timer8& TC;
  
};

#endif
