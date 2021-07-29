/*
 *  (C) 2021 MEAN00 fixounet@free.fr
 *  See license file
 */
#include "lnArduino.h"
#include "lnPeripheral_priv.h"
#include "lnADC.h"
#include "lnADC_priv.h"
#include "lnBasicTimer.h"
#include "lnDma.h"
#include "lnPinMapping.h"
/**
 */
#define NB_VCC_AVERAGE 8
/**
 * 
 * @param instance
 * @param pin
 */
lnSimpleADC::lnSimpleADC(int instance, lnPin pin)  : lnBaseAdc(instance)
{
    LN_ADC_Registers *adc=lnAdcDesc[_instance].registers;
    _pin=pin;
    setPin(pin);   
    setup();
    
}
/**
 * 
 */
lnSimpleADC::~lnSimpleADC()
{

}
/**
 * 
 * @param pin
 * @return 
 */

/**
 * 
 */
void   lnSimpleADC:: setup()
{
  LN_ADC_Registers *adc=lnAdcDesc[_instance].registers;
  lnBaseAdc::setup();
  adc->RSQS[2]=adcChannel(_pin);
  adc->RSQS[0]=0<<20; // one channel
  
}
/**
 * 
 * @return 
 */
lnPin   lnSimpleADC::pin()
{
    return _pin;
}
/**
 * 
 * @param pin
 * @return 
 */
bool    lnSimpleADC::setPin(lnPin pin)
{
    _pin=pin;    
    setup();
    return true;
}
/**
 * 
 * @return 
 */
int     lnSimpleADC::simpleRead()
{
    int value;
    if(!pollingMultiRead(1,&_pin,&value)) return -1;
    return value;
}
/**
 * 
 * @param nbPins
 * @param pins
 * @param output
 * @return 
 */
bool    lnSimpleADC::pollingMultiRead(int nbPins, lnPin *pins, int *output)
{
    xAssert(nbPins<=5);
    LN_ADC_Registers *adc=lnAdcDesc[_instance].registers;
    xAssert(nbPins);
    // adc Off    
    // 1 sample => 0
    adc->RSQS[0]=0;
    for(int i=0;i<nbPins;i++)
    {
        uint32_t rsq2=adcChannel(pins[i]);
        adc->RSQS[2]=rsq2;        
        adc->CTL1|=LN_ADC_CTL1_SWRCST;
        while( !((adc->STAT & LN_ADC_STAT_EOC)))
        {
            __asm__("nop");
        }
        int data=adc->RDATA ;
        // Retrieve data
        output[i]=data&0xfff;
    }
    return true;
}


// EOF