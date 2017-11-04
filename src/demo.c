//Nate Zimmer UART example
// Press button to print hello to terminal

#include "lazy.h"
#include "uart.h"

#define BUTTON    BIT3
typedef enum {IDLE, BUTTON_PRESSED, LONG} State;

int main(void)
{
    WDTCTL = WDTPW + WDTHOLD;         // Stop Watch dog timer
    BCSCTL1 = CALBC1_1MHZ;            // Set DCO to 1 MHz
    DCOCTL = CALDCO_1MHZ;
    P1DIR &=~BUTTON;                  // Ensure button is input (sets a 0 in P1DIR register at location BIT3)

     P1OUT |=  BUTTON;                 // Enables pullup resistor on button
     P1REN |=  BUTTON;
	 uart_setup();
     State state = IDLE;
     while(1)                          // While 1 is equal to 1 (forever)
     {
        switch(state){
             case IDLE:
                if(!((P1IN & BUTTON)==BUTTON)) // Was button pressed?
                {
                    state = BUTTON_PRESSED;
                    __delay_cycles(100000); //Debounce button so signal is not sent multiple times
                }
                break;
             case BUTTON_PRESSED:
                if(!((P1IN & BUTTON)==BUTTON)) // Was button pressed?
                {
                    state = LONG;
                }
                else{
                    uart_tx_string(".\r\n");
                    state = IDLE;
                }
                break;
             case LONG:
                if(((P1IN & BUTTON)==BUTTON)) // Was button released?
                {
                    uart_tx_string("-\r\n");
                    state = IDLE;
                }                
                break;
             default:
                state = IDLE;
                break;
         }
     }
}

