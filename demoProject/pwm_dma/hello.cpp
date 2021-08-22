#include "lnArduino.h"
#include "lnTimer.h"


#define LED LN_SYSTEM_LED

#define PWM_PIN PA6

void setup()
{
    pinMode(LED,OUTPUT);    
}



void loop()
{
    bool onoff=true;
    digitalWrite(LED,true);
    int roundup=0;
    
    uint16_t sequence[]=
    {
        10,20,30,40,50,60,70,80,90
    };
    
    lnPinMode(PWM_PIN,lnALTERNATE_PP);    
    lnDmaTimer timer(PWM_PIN);
    
    timer.pwmSetup(810000);
    int rollover=timer.rollover();
    int n=sizeof(sequence)/sizeof(uint16_t);
    for(int i=0;i<n;i++)
        sequence[i]=(sequence[i]*rollover)/100;
    
    while(1)
    {
           timer.start(n,sequence);
    }
    
}
