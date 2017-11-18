#ifndef _GPIO_H_
#define _GPIO_H_

#include "lazy.h"



typedef enum {LOW, HIGH} Level;


typedef enum {C_IN, C_OUT, C_IN_PULLUP} Configuration;

RC gpio_configure(uint8_t bank, uint8_t pin, Configuration configuration);

RC gpio_write(uint8_t bank, uint8_t pin, Level level);

#endif // _GPIO_H_
