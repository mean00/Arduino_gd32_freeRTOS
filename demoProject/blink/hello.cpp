#include "lnArduino.h"
#include "lnSPI.h"
// green = PA1, blue = PA2, RED PC13
#define LED PA2

uint8_t ucHeap[configTOTAL_HEAP_SIZE];

extern "C"
{
    void _init();    
}

class Demo : public xTask
{
public:
        Demo(): xTask("Demo",5,250)
            {
                roundup=0;
            }
    void run (void);

    int roundup;    
};



/**
 * 
 */
void Demo::run()
{
    pinMode(LED,OUTPUT);
    bool onoff=true;
    digitalWrite(LED,HIGH);
    uint8_t data[5]={0x55,0xAA,0x55,0xAA,0x55};
    hwlnSPIClass *spi=new hwlnSPIClass(0); // SPI 0
    spi->begin();
    lnSPISettings settings(2*1000,SPI_MSBFIRST,SPI_MODE0,-1);
    spi->beginTransaction(settings);
    while(1)
    {
        roundup++;
      //  vTaskDelay(500);
        digitalToggle(LED);
        spi->write(5,data);
        onoff=!onoff;
        Logger("*\n");
    }
}

extern "C" void _exit(int x);
/**
 */
int main()
{
    // Initialize system
    _init();
    
    eclic_priority_group_set(ECLIC_PRIGROUP_LEVEL4_PRIO0); //四位优先级组全配置为lvl
    eclic_global_interrupt_enable();                       //使能全局中断
    
    // The LEDs are all on GPIO A
    rcu_periph_clock_enable(RCU_GPIOA);
    // We need alternate functions too
    rcu_periph_clock_enable(RCU_AF); 
    //
    LoggerInit();
    Logger("Starting demo:\n");
    // Start freertos
    Demo *demo=new Demo;     
    vTaskStartScheduler();      
    deadEnd(25);
    
}


extern "C" void deadEnd(int code)
{
    // No interrrupt
    ENTER_CRITICAL();
    while(1)
    {
        // blink red light...
        
    }
}