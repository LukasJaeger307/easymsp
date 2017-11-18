#ifndef _GNAMPF_H_
#define _GNAMPF_H_

#include "lazy.h"

#define ONE_WIRE_PIN BIT4
#define ONE_WIRE_IN P1IN
#define ONE_WIRE_OUT P1OUT
#define ONE_WIRE_DIR P1DIR

float get_temp(void);
void reset_18B20(void);
void send_18B20(char data);
unsigned int read_18B20(void);

#endif
