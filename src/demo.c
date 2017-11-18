#include "lazy.h"
#include "uart.h"
#include "gpio.h"

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
		RC rc = gpio_read(1, 3, &level);
		if (rc != 0x00){
			uart_tx_string("Read failed\r\n");
		}
		gpio_write(1, 6, ~level);
	}
}

