#ifndef _GPIO_H_
#define _GPIO_H_

#include "lazy.h"

#define HIGH (0xFF)

#define LOW (0x00)

typedef enum {C_IN, C_OUT, C_IN_PULLUP} Configuration;

RC gpio_configure(uint8_t bank, uint8_t pin, Configuration configuration);

RC gpio_write(uint8_t bank, uint8_t pin, uint8_t level);

RC gpio_read(uint8_t bank, uint8_t pin, uint8_t * const data);

#endif // _GPIO_H_
