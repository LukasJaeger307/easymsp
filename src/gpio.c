#include "gpio.h"

RC gpio_configure(uint8_t bank, uint8_t pin, Configuration configuration){
	// Pin bank 1 (obviously)
	if (bank == 1){
		// Checking, whether the pin exists
		if (pin > 7){
			return 0xFF;
		}
		else{
			uint8_t mask = (1 << pin);
		// Doing the actual configuration
		switch (configuration){
			case C_IN:
				P1DIR &= ~mask;      
				return 0x00;
			case C_IN_PULLUP:
				P1DIR &= ~mask;      
				P1OUT |= mask;
				P1REN |= mask;
				return 0x00;
			case C_OUT:
				P1DIR |= mask;      
				return 0x00;
			default:
				return 0xFF;
		}
		}
	} if (bank == 2){
		// Checking, whether the pin exists
		if (pin > 5){
			return 0xFF;
		}
		else{
			uint8_t mask = (1 << pin);
		// Doing the actual configuration
		switch (configuration){
			case C_IN:
				P2DIR &= ~mask;      
				return 0x00;
			case C_IN_PULLUP:
				P2DIR &= ~mask;      
				P2OUT |= mask;
				P2REN |= mask;
				return 0x00;
			case C_OUT:
				P2DIR |= mask;      
				return 0x00;
			default:
				return 0xFF;
		}
		}
	} else {
		return 0xFF;
	}
}

RC gpio_write(uint8_t bank, uint8_t pin, uint8_t level){
	if (bank == 1){
		if (pin > 7){
			return 0xFF;
		}
		else{
			uint8_t mask = (1 << pin);
			if (level != 0){
				P1OUT |= mask;
				return 0x00;
			}
			else{

				P1OUT &= ~mask;
				return 0x00;
			}
		}
	}
	else if (bank == 2){
		if (pin > 5){
			return 0xFF;
		}
		else{
			uint8_t mask = (1 << pin);
			if (level != 0){
				P1OUT |= mask;
				return 0x00;
			}
			else{

				P1OUT &= ~mask;
				return 0x00;
			}
		}
	}
	else{
		return 0xFF;
	}
}


RC gpio_read(uint8_t bank, uint8_t pin, uint8_t * const data){
	if (bank == 1){
		if (pin > 7) {
			 return 0xFF;
		}
		else {
			uint8_t mask = 1 << pin;
			if ((P1IN & mask) != 0){
				*data = HIGH;
			} else {
				*data = LOW;
			}
			return 0x00;
		}
	} else if (bank == 2){
		if (pin > 5){
			return 0xFF;
		}
		else {
			uint8_t mask = 1 << pin;
			if ((P2IN & mask) != 0){
				*data = HIGH;
			} else {
				*data = LOW;
			}
			return 0x00;
		}
	} else{
		return 0xFF;
	}
}
