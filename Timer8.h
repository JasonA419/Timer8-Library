#ifndef Timer8_h
#define Timer8_h

#include "Arduino.h"
#include "Output8.h"

enum timer0 : uint8_t
{
  T0 = 0
};

enum timer2 : uint8_t
{
  T2 = 2
};

class Timer8
{
  friend class Output8;
  
public:
  enum prescaler : uint8_t
  {
    OFF = 0,
    DIV_1 = 1,
    DIV_8 = 2,
    DIV_32 = 3,
    DIV_64 = 4,
    DIV_128 = 5,
    DIV_256 = 6,
    DIV_1024 = 7
  };
  
  enum mode : uint8_t
  {
    NORMAL = 0,
    PC = 1,
    CTC_ATOP = 2,
    FAST = 3,
    PC_ATOP = 5,
    FAST_ATOP = 7,
  };
  
  enum interrupt : uint8_t
  {
    TIMER_OVERFLOW = 1,
    OUTPUT_COMPARE_A = 2,
    OUTPUT_COMPARE_B = 4,
    ALL = 255
  };
  
protected:
  void initRegisters();
  volatile uint8_t& RegisterA;
  volatile uint8_t& RegisterB;
  volatile uint8_t& IntMaskRegister;
  volatile uint8_t& IntFlagRegister;
  uint8_t Prescaler;
  volatile uint8_t& TimerCounter;
  const uint8_t CLOCK_MASK = B00000111;
  
public:
  Timer8(timer0 n);
  Timer8(timer2 n);
  void enable();
  void disable();
  boolean isEnabled();
  void clearTimer();
  boolean is16Bit() {return false;};
  boolean is8Bit() {return true;};
  void setCount(uint8_t count);
  uint8_t getCount();
  void setPrescaler(prescaler p);
  void setMode(mode m);
  void enableInt(interrupt f);
  void enableInt(uint8_t f);
  void disableInt(interrupt f);
  void disableInt(uint8_t f);
  void clearFlag(interrupt f);
  void clearFlag(uint8_t f);
  Output8 A;
  Output8 B;
  
};

#endif
