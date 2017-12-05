
#include "Timer8.h"


Timer8::Timer8(timer0 n) : RegisterA(TCCR0A), RegisterB(TCCR0B), IntMaskRegister(TIMSK0), IntFlagRegister(TIFR1), TimerCounter(TCNT0), A(Output8::OUTPUT_A, OCR0A, DDRB, PORTB, PB7, *this), B(Output8::OUTPUT_B, OCR0B, DDRG, PORTG, PG5, *this)
{
  Prescaler = 0;
  initRegisters();
}

Timer8::Timer8(timer2 n) : RegisterA(TCCR2A), RegisterB(TCCR2B), IntMaskRegister(TIMSK2), IntFlagRegister(TIFR1), TimerCounter(TCNT2), A(Output8::OUTPUT_A, OCR2A, DDRB, PORTB, PB4, *this), B(Output8::OUTPUT_B, OCR2B, DDRH, PORTH, PH6, *this)
{
  Prescaler = 0;
  initRegisters();
}

void Timer8::enable()
{
  RegisterB |= Prescaler;
}

void Timer8::disable()
{
  RegisterB &= ~(CLOCK_MASK);
}

boolean Timer8::isEnabled()
{
  return ((RegisterB & CLOCK_MASK) > 0);
}

void Timer8::initRegisters()
{
  RegisterA = 0;
  RegisterB = 0;
  IntMaskRegister = 0;
  IntFlagRegister = 255;
}

void Timer8::setCount(uint8_t count)
{
  TimerCounter = count;
}

uint8_t Timer8::getCount()
{
  return TimerCounter;
}
void Timer8::setPrescaler(prescaler p)
{
  Prescaler = p;
//  RegisterB |= Prescaler;
}

void Timer8::setMode(mode m)
{
  RegisterA |= (B00000011 & m);          // bits 0 & 1 of Register A are WGM bits 0 & 1
  RegisterB |= ((B00001100 & m) << 1);   // Bits 3 & 4 of Register A are WGM bits 2 & 3 (hence the bit-shift)
}

void Timer8::enableInt(interrupt f)
{
  IntMaskRegister |= f;
}

void Timer8::enableInt(uint8_t f)
{
  IntMaskRegister |= f;
}

void Timer8::disableInt(interrupt f)
{
  IntMaskRegister &= ~(f);
}

void Timer8::disableInt(uint8_t f)
{
  IntMaskRegister &= ~(f);
}

void Timer8::clearFlag(interrupt f)
{
  IntFlagRegister |= f;
}

void Timer8::clearFlag(uint8_t f)
{
  IntFlagRegister |= f;
}

