#include "lazy.h"
#include "uart.h"
#include "gpio.h"
#include "gnampf.h"
#include <stdio.h>

#define BUTTON BIT3

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;         // Stop Watch dog timer
	BCSCTL1 = CALBC1_1MHZ;            // Set DCO to 1 MHz
	DCOCTL = CALDCO_1MHZ;

	gpio_configure(1,3, C_IN_PULLUP);
	gpio_configure(1,6, C_OUT);

	uart_setup();
	while(1)                          // While 1 is equal to 1 (forever)
	{
		uint8_t level = LOW;
		float temperature = get_temp();//0.0;
		//ds_get_temperature(1,7, &temperature);
		
		char dings [10];
		sprintf(dings, "%u.%02u", (int) temperature, (int) ((temperature - (float)((int)(temperature))) * 100));
		uart_tx_string("Temperature: ");
		uart_tx_string(dings);
		uart_tx_string("\r\n");
		__delay_cycles(1000000);
	}
}

