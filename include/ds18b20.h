#ifndef _DS18B20_H_
#define _DS18B20_H_

#include "lazy.h"


RC ds_initialize(uint8_t bank, uint8_t pin);


RC ds_send_char(uint8_t bank, uint8_t pin, uint8_t data);


RC ds_read_char(uint8_t bank, uint8_t pin, uint16_t * const data);


RC ds_get_temperature(uint8_t bank, uint8_t pin, float * const data);


void ftoa(float f, char * const string);

#endif // _DS18B20_H_
