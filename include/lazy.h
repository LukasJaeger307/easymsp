/**\file */
#ifndef _LAZY_H_
#define _LAZY_H_

/**\page lazy The lazy-header
  * Don't you hate to include a bunch of headers that you use in every c-file
  * anyway manually? That's what the _lazy_-header is doing. It includes _msp430.h_
  * _stdlib.h_ and _stdint.h_
  */


#include <msp430.h>
#include <stdlib.h>
#include <stdint.h>

#define MHZ 1

typedef uint8_t RC;

#define RNN(x){		\
	RC tmp = (x);	\
	if (tmp != 0){	\
		return tmp;	\
	}				\
}

#define BM(x) (1 << (x))

#define OK (0x00)

#define ERR (0xFF)

#endif //_LAZY_H_
