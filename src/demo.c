//Nate Zimmer UART example
// Press button to print hello to terminal

#include "lazy.h"
#include "uart.h"
#include "gpio.h"

int main(void)
{
	WDTCTL = WDTPW + WDTHOLD;         // Stop Watch dog timer
	BCSCTL1 = CALBC1_1MHZ;            // Set DCO to 1 MHz
	DCOCTL = CALDCO_1MHZ;

	gpio_configure(1,6, C_OUT);

	uart_setup();
	while(1)                          // While 1 is equal to 1 (forever)
	{
		uart_tx_string("Moin!\r\n");
		gpio_write(1,6, HIGH);
		__delay_cycles(1000000);
		gpio_write(1,6, LOW);
		__delay_cycles(1000000);	
	}
}

