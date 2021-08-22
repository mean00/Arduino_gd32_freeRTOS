/*
 *  (C) 2021 MEAN00 fixounet@free.fr
 *  See license file
 *  Each bit in the WS2812B_timer stream becomes a byte
 * 
 *  writing the new PWM value takes ~ 4us on a GD32F303 @ 72 Mhz
 *  so about 7 us
 */
#include "lnArduino.h"
#include "lnWS2812B_timer.h"


#define WS_PREAMBLE 4*24 // number of zero byte preamble

/**
 * 
 * @param nbLeds
 * @param s
 */
WS2812B_timer::WS2812B_timer(int nbLeds, int pin) : WS2812B_base(nbLeds)
{
   _pin=pin;
   _timer=new lnDmaTimer(pin);
}
/**
 * 
 */
void WS2812B_timer::begin()
{
    lnPinMode(_pin,lnPWM);
   if(!_timer->pwmSetup(830000)) 
   {
       xAssert(0);
   }
   _one=(_timer->rollover()*4+3)/6;
   _zero=(_timer->rollover()*2+3)/6;   
   _timer->attachDmaCallback(this);
   uint16_t *target=lookup;
   // Pre compute PWM for 4 bits value
   for(int value=0;value<16;value++)
   {
       int copy=value;
       for(int i=0;i<4;i++)
       {
            if(copy & 0x8) *target=_one;
            else *target=_zero;
            target++;
            copy<<=1;
        }
   }   
}

/**
 */
WS2812B_timer::~WS2812B_timer()
{
}
void WS2812B_timer::convertOne(uint8_t value, uint16_t *target)
{
    int high=(value>>4)&0xf;
    int low=value&0xf;
    memcpy(target,lookup+high*4 ,2*4);
    memcpy(target+4,lookup+low*4,2*4);
}
/**
 * 
 * @param hilow
 * @param rgb
 */
 uint32_t delta;
void WS2812B_timer::convertRgb(int hilow, uint8_t *rgb)
{
    uint16_t *p=_timerPwmValue;
    if(hilow) p+=24;
    convertOne(rgb[0],p);
    convertOne(rgb[1],p+8);
    convertOne(rgb[2],p+16);
}

 /**
  * 
  */
 void WS2812B_timer::update()
 {
    _nextLed=2;
    convertRgb(false,_ledsColor);
    convertRgb(true,_ledsColor+3);
    // start PWM 
    _timer->start(48,_timerPwmValue);
    _sem.take(100);
    _timer->stop();
    
 }
/**
 * 
 * @param half
 * @return 
 */
bool   WS2812B_timer::timerCallback(bool half)
{
    if(_nextLed<_nbLeds)
    {
        convertRgb(!half,_ledsColor+3*_nextLed);
        _nextLed++;
        return true;     
    }
    
    if(_nextLed==_nbLeds)
    {
        // ok we just wrote the last one, it is not sent yet
        return true;     
    }
    if(_nextLed==_nbLeds+1)
    {
         _sem.give();
        _nextLed++;
        return true;     
    }
    return true;
}
// EOF
 