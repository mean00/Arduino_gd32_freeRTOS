
/*
 *  (C) 2021 MEAN00 fixounet@free.fr
 *  See license file
 */
#include "lnArduino.h"
#include "lnPinMapping.h"


const LN_PIN_MAPPING pinMappings[]=
{
    // PIN      ADC     TIMER       TIMERCHANNEL  DAC
    {  PA0,      0,     1,          0              ,-1},
    {  PA1,      1,     1,          1              ,-1},
    {  PA2,      2,     1,          2              ,-1},
    {  PA3,      3,     1,          3              ,-1 },
    {  PA4,      4,     -1,         -1             ,0 },
    {  PA5,      5,     -1,         -1             ,1 },
    {  PA6,      6,     2,         0              ,-1},
    {  PA7,      7,     2,         0              ,-1},
    {  PA8,     -1,     0,         0              ,-1},
    {  PA9,     -1,     0,         1              ,-1},
    {  PA10,    -1,     0,         2              ,-1},
    {  PA11,    -1,     0,         3              ,-1},
    {  PA12,    -1,     -1,         -1            ,-1  },
    {  PA13,    -1,     -1,         -1            ,-1  },
    {  PA14,    -1,     -1,         -1            ,-1  },
    {  PA15,    -1,     -1,         -1            ,-1  },
    {  PB0,     8,     2,           2             ,-1 },
    {  PB1,     9,     2,           3             ,-1 },
    {  PB2,     -1,     -1,         -1            ,-1  },
    {  PB3,     -1,     1,         1              ,-1},
    {  PB4,     -1,     2,         0              ,-1},
    {  PB5,     -1,     2,         1              ,-1},
    {  PB6,     -1,     3,         0              ,-1},
    {  PB7,     -1,     3,         1              ,-1},
    {  PB8,     -1,     3,         2              ,-1},
    {  PB9,     -1,     3,         3              ,-1},
    {  PB10,    -1,     1,         2              ,-1},
    {  PB11,    -1,     1,         3              ,-1},
    {  PB12,    -1,     -1,         -1            ,-1  },
    {  PB13,    -1,     -1,         -1            ,-1  },
    {  PB14,    -1,     -1,         -1            ,-1  },
    {  PB15,    -1,     -1,         -1            ,-1  },
    {  PC0,     -1,     -1,         -1            ,-1  },
    {  PC1,     -1,     -1,         -1            ,-1  },
    {  PC2,     -1,     -1,         -1            ,-1  },
    {  PC3,     -1,     -1,         -1            ,-1  },
    {  PC4,     -1,     -1,         -1            ,-1  },
    {  PC5,     -1,     -1,         -1            ,-1  },
    {  PC6,     -1,     -1,         -1            ,-1  },
    {  PC7,     -1,     -1,         -1            ,-1  },
    {  PC8,     -1,     -1,         -1            ,-1  },
    {  PC9,     -1,     -1,         -1            ,-1  },
    {  PC10,    -1,     -1,         -1            ,-1  },
    {  PC11,    -1,     -1,         -1            ,-1  },
    {  PC12,    -1,     -1,         -1            ,-1  },
    {  PC13,    -1,     -1,         -1            ,-1  },
    {  PC14,    -1,     -1,         -1            ,-1  },
    {  PC15,    -1,     -1,         -1            ,-1  },
    {  PD0,     -1,     -1,         -1            ,-1  },
    {  PD1,     -1,     -1,         -1            ,-1  },
    {  PD2,     -1,     -1,         -1            ,-1  },
    {  PD3,     -1,     -1,         -1            ,-1  },
    {  PD4,     -1,     -1,         -1            ,-1  },
    {  PD5,     -1,     -1,         -1            ,-1  },
    {  PD6,     -1,     -1,         -1            ,-1  },
    {  PD7,     -1,     -1,         -1            ,-1  },
    {  PD8,     -1,     -1,         -1            ,-1  },
    {  PD9,     -1,     -1,         -1            ,-1  },
    {  PD10,    -1,     -1,         -1            ,-1  },
    {  PD11,    -1,     -1,         -1            ,-1  },
    {  PD12,    -1,     -1,         -1            ,-1  },
    {  PD13,    -1,     -1,         -1            ,-1  },
    {  PD14,    -1,     -1,         -1            ,-1  },
    {  PD15,    -1,     -1,         -1            ,-1  },
    {  -1  ,    -1,     -1,         -1            ,-1  },
};
