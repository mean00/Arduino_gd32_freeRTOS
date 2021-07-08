/*
 *  (C) 2021 MEAN00 fixounet@free.fr
 *  See license file
 */

#include "lnArduino.h"
#include "lnRCU.h"
#include "lnIRQ.h"
#include "lnIRQ_arm_priv.h"
#include "lnSCB_arm_priv.h"
/**
 * 
 */

#define LN_NB_INTERRUPT 68
LN_SCB_Registers *aSCB=(LN_SCB_Registers *)0xE000ED00;
static uint32_t interruptVector[LN_NB_INTERRUPT]  __attribute__((aligned(256)));

extern "C" void xPortPendSVHandler();
extern "C" void xPortSysTickHandler();

static void unsupportedInterrupt()
{
    xAssert(0);
}
void lnIrqSysInit()
{
    //
    uint32_t unsupported=(uint32_t )unsupportedInterrupt;
    for(int i=0;i<LN_NB_INTERRUPT;i++)
        interruptVector[i]=unsupported;
    
    // Hook in SVC
    interruptVector[14]=(uint32_t)xPortPendSVHandler;
    interruptVector[15]=(uint32_t)xPortSysTickHandler;
    
    // Hook basic interrupts
    
    
    // Relocate vector to there    
    aSCB->VTOR = (uint32_t)interruptVector;
    __asm__ __volatile__("dsb sy") ;
    return;
}

void _enableDisable(bool enableDisable, const LnIRQ &irq)
{
  
}
/**
 * 
 * @param irq
 */
extern "C" void lnEnableInterruptDirect(int irq)
{   
    
}
/**
 * 
 * @param irq
 */
extern "C" void lnDisableInterruptDirect(int irq)
{   
   
}

/**
 * 
 * @param per
 */
void lnEnableInterrupt(const LnIRQ &irq)
{   
    _enableDisable(true,irq);   
}
/**
 * 
 * @param per
 */
void lnDisableInterrupt(const LnIRQ &irq)
{
     _enableDisable(false,irq);
}


#define DMA_IRQ(d,c) extern "C" void DMA##d##_Channel##c##_IRQHandler(void) { dmaIrqHandler(d,c);}
/**
 * 
 * @param dma
 * @param channel
 */
void dmaIrqHandler(int dma, int channel);
DMA_IRQ(0,0)
DMA_IRQ(0,1)
DMA_IRQ(0,2)
DMA_IRQ(0,3)
DMA_IRQ(0,4)
DMA_IRQ(0,5)
DMA_IRQ(0,6)
DMA_IRQ(1,0)
DMA_IRQ(1,1)
DMA_IRQ(1,2)
DMA_IRQ(1,3)
DMA_IRQ(1,4)
DMA_IRQ(1,5)
DMA_IRQ(1,6)
  
/**
 * I2C
 * @param code
 */     
void i2cIrqHandler(int instance, bool error);
#define I2C_IRQ(d) extern "C" void I2C##d##_EV_IRQHandler(void) { i2cIrqHandler(d,false);} \
                   extern "C" void I2C##d##_ERR_IRQHandler(void) { i2cIrqHandler(d,true);} 

I2C_IRQ(0)
I2C_IRQ(1)

extern "C" void deadEnd(int code)
{
    // No interrrupt
    ENTER_CRITICAL();
    while(1)
    {
        // blink red light...
        
    }
}        
// EOF
