#include "gnampf.h"

float get_temp(void)
{
    unsigned int temp;
    reset_18B20();
    send_18B20(0xcc);   //send CCH,Skip ROM command
    send_18B20(0x44);
    __delay_cycles(100);

    reset_18B20();
    send_18B20(0xcc);   //send CCH,Skip ROM command
    send_18B20(0xbe);

    temp = read_18B20();
    return((float)temp/8.0);

}

void reset_18B20(void)
{
    ONE_WIRE_DIR |=ONE_WIRE_PIN;
    ONE_WIRE_OUT &= ~ONE_WIRE_PIN;
    __delay_cycles(500);
    ONE_WIRE_OUT |=ONE_WIRE_PIN;
    ONE_WIRE_DIR &= ~ONE_WIRE_PIN;
    __delay_cycles(500);
}

void send_18B20(char data)
{
    char i;

    for(i=8;i>0;i--)
    {
    	ONE_WIRE_DIR |=ONE_WIRE_PIN;
        ONE_WIRE_OUT &= ~ONE_WIRE_PIN;
        __delay_cycles(2);
        if(data & 0x01)
        {
            ONE_WIRE_OUT |= ONE_WIRE_PIN;
        }
        __delay_cycles(60);
        ONE_WIRE_OUT |= ONE_WIRE_PIN;
        ONE_WIRE_DIR &= ~ONE_WIRE_PIN;
        data >>=1;
    }
}

unsigned int read_18B20()
{
    char i;
    unsigned int data=0;

    for(i=16;i>0;i--)
    {
    	ONE_WIRE_DIR |= ONE_WIRE_PIN;
        ONE_WIRE_OUT &= ~ONE_WIRE_PIN;
        __delay_cycles(2);
        ONE_WIRE_OUT |=ONE_WIRE_PIN;
        ONE_WIRE_DIR &= ~ONE_WIRE_PIN;
        __delay_cycles(8);
        if(ONE_WIRE_IN & ONE_WIRE_PIN)
        {
            data |=0x8000;
        }
        data>>=1;
        __delay_cycles(120);
    }
    return(data);
}
