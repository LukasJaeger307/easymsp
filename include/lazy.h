/**\file */
#ifndef _LAZY_H_
#define _LAZY_H_

/**\page lazy The lazy-header
  * Don't you hate to include a bunch of headers that you use in every c-file
  * anyway manually? That's what the _lazy_-header is doing. It includes _msp430.h_
  * _stdlib.h_ and _stdint.h_ and defines a handful of helpful macros.
  */


#include <msp430.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * The frequency of the MSP's internal oscillator
 */
#define MHZ 1

/**
 * A return code for functions
 */
typedef uint8_t RC;

/**
 * Return if Not Null
 */
#define RNN(x){		\
	RC tmp = (x);	\
	if (tmp != 0){	\
		return tmp;	\
	}				\
}

/**
 * Bitmask macro
 */
#define BM(x) (1 << (x))

/**
 * OK return code
 */
#define OK (0x00)

/**
 * Error return code
 */
#define ERR (0xFF)

#endif //_LAZY_H_
