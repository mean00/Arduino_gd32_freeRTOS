#pragma once
#include "stdint.h"

struct tusb_desc_device_t;
struct tusb_desc_device_qualifier_t;


typedef void lnUsbStackEventHandler(void *cookie, const int event);


struct lnusb_c
{

};

lnusb_c *   lnusb_create(uint32_t instance);
void        lnusb_delete(lnusb_c *);

void lnusb_init(lnusb_c *inst, int nbDescriptorLine, const char **deviceDescriptor);
void lnusb_setConfiguration(lnusb_c *inst, const uint8_t *hsConfiguration, const uint8_t *fsConfiguration,
                          const tusb_desc_device_t *desc, const tusb_desc_device_qualifier_t *qual);
   
void lnusb_setEventHandler(lnusb_c *inst, const void *cookie, lnUsbStackEventHandler *ev);
void lnusb_start(lnusb_c *inst );
void lnusb_stop(lnusb_c *inst);
          
// EOF