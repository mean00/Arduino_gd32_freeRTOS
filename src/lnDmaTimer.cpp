/*
 *  (C) 2021 MEAN00 fixounet@free.fr
 *  See license file
 */
#include "lnArduino.h"
#include "lnTimer.h"
#include "lnTimer_priv.h"
#include "lnPinMapping.h"

extern LN_Timers_Registers *aTimers[4];
/**
 * 
 * @param timer
 * @param channel
 * @param dmaEngine
 * @param dmaChannel
 * @return 
 */
static bool searchDma(int timer, int channel, int &dmaEngine,int &dmaChannel)
{
    const LN_TIMER_MAPPING *m=timerMappings;
    int key=10*timer+channel;
    while(m->TimerChannel!=-1)
    {
        if(m->TimerChannel==key)
        {
            dmaEngine=m->dmaEngine;
            dmaChannel=m->dmaChannel;
            return true;
        }
        m++;
    }
    xAssert(0);
    return false;
}


/**
 * 
 * @param pin
 */
lnDmaTimer::lnDmaTimer(int pin) : lnTimer(pin)
{
    const LN_PIN_MAPPING *pins=pinMappings;
    int dmaChannel=-1;
    int dmaEngine=-1;
    _timer=-1;
    while(1)
    {
        xAssert(pins->pin!=-1); //t2c1
        if(pins->pin==pin)
        {
            _timer=pins->timer;
            _channel=pins->timerChannel;
            break;
        }
        pins++;
    }
    if(_timer==-1) xAssert(0);
    searchDma(_timer,_channel,dmaEngine,dmaChannel);
    _dma=new lnDMA(lnDMA::DMA_MEMORY_TO_PERIPH,dmaEngine,dmaChannel,16,16);
}
/**
 * 
 */
lnDmaTimer:: ~lnDmaTimer()
{
    if(_dma)
    {
        delete _dma;
        _dma=NULL;
    }
}
/**
 * 
 * @param frequency
 * @return 
 */
bool    lnDmaTimer::pwmSetup(int frequency)
{
    LN_Timers_Registers *t=aTimers[_timer-1];
    setTickFrequency(frequency);
    _rollover=t->CAR+1;
    setMode(lnTimerModePwm1);
    return true;
}
/**
 * 
 * @return 
 */
int     lnDmaTimer::rollover()
{
    return _rollover;
}
/**
 * 
 * @param cb
 * @return 
 */
bool    lnDmaTimer::attachDmaCallback(lnDmaTimerCallback *cb)
{
    _cb=cb;
    return true;
}
/**
 * 
 * @param nbSample
 * @param data
 * @return 
 */


static void _dmaTimerCallback(void *c, lnDMA::DmaInterruptType typ)
{
    lnDmaTimer *t=(lnDmaTimer *)c;
    bool h=false;
    if(lnDMA::DMA_INTERRUPT_HALF==typ) h=true;
    t->dmaInterrupt(h);
}
/**
 * 
 */
void lnDmaTimer::dmaInterrupt(bool h)
{
    xAssert(_cb);
    _cb->timerCallback(h);
}
/**
 * 
 */
void    lnDmaTimer::stop()
{
    LN_Timers_Registers *t=aTimers[_timer-1];
    // disable timer
    disable();
    t->DMAINTEN&=~(1<<(_channel+9));  
    _dma->endTransfer();
}

/**
 * 
 * @param nbSample
 * @param data
 * @return 
 */
bool    lnDmaTimer::start(int nbSample, uint16_t *data)
{   
    LN_Timers_Registers *t=aTimers[_timer-1];
    
    _dma->beginTransfer(); // lock dma
    _dma->attachCallback(_dmaTimerCallback,this);
    // circular, no repeat, both interrupt
                                                                                    //  bool repeat,bool circular,bool  bothInterrupts)
    _dma->doMemoryToPeripheralTransferNoLock(nbSample,(uint16_t *)data,(uint16_t *)&(t->CHCVs[_channel]),false,true,true);                
    // PWM mode 1
    t->CHCVs[_channel]=_rollover/2;
    t->DMAINTEN|=1<<(_channel+9);
    enable();
    return true;
}



/**
 * 
 * @param fq
 * @return 
 */
  bool    lnDmaTimer::setTickFrequency(int fqInHz)
  {        
    LN_Timers_Registers *t=aTimers[_timer-1];
    Peripherals per=pTIMER1;
    per=(Peripherals)((int)per+_timer-1);
    uint32_t clock=lnPeripherals::getClock(per);
    // If ABP1 prescale=1, clock*=2 ???? see 5.2 in GD32VF103
    // disable
    t->CTL0&=~LN_TIMER_CTL0_CEN;
   
    int divider=(clock+fqInHz/2)/(fqInHz);
    divider*=2;

#warning FIXME we assume no prescaler needed
    t->PSC=0;

    if(!divider) divider=1;
    t->CAR=divider-1;
    return true;
  }

// EOF
