/*
 * justmisra.h
 *
 *  Created on: Oct 29, 2014
 *      Author: Administrator
 */

#ifndef MSP430_H_
#define MSP430_H_

#include <msp430f5527.h>

unsigned char RC5_Read(void);
void Delay(unsigned int tic);
void rc5_Init(void);
void rc5_operation(void);


#endif
