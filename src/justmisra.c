/*
 * justmisra.c
 *
 *  Created on: Oct 29, 2014
 *      Author: Administrator
 */

#include"justmisra.h"

#define led1       0x0001
#define led2       0x0002
#define led3       0x0004
#define led4       0x0008
#define led5       0x0010
#define led6       0x0020
volatile unsigned char i;
void Delay(unsigned int tic)
{
        while(tic!=0)
        {
                i=140;
                while(i!=0)
                {
                i--;
                }
                tic--;
        }
}
volatile unsigned int i1=170;
void Delay_RC5(void)
{

        while(i1!=0)
        {
        i1--;
        }
}
unsigned char temp,j,k;
unsigned char RC5_Read(void)
{
        k=0;
                             /* wait 3.5 MS to ensure the channel is free   */
        for(j=0;j<6;++j)
        {
                Delay_RC5();
                if(k==0)
                return 255;     /* if not free, return 0    */
        }

        j=130;
          while(j!=0 && k==1)
        {
                Delay_RC5();
                j--;
        }
        if(j==0)
        return  255;
        while(k==0);


        for(j=12;j!=0;--j)
        {
                Delay_RC5();
                if(j<7)
                {
                temp= ((temp<<1)|| k);
                }
                if(k==1)
                while(k==1);
                else
                while(k==0);
        }
        return temp;
}
void rc5_Init(void)
{
	P2DIR |= led1;                                         /*  Set P1.0 to output direction....*/
	                P2OUT &= ~led1;                                 /*  Set led1 off.....*/

	                P2DIR |= led2;                                         /*  Set P1.1 to output direction....*/
	                P2OUT &= ~led2;                                 /*  Set led1 off....*/

	                P2DIR |= led3;                                         /*  Set P1.2 to output direction....*/
	                P2OUT &= ~led3;                                 /*  Set led1 off...*/

	                P2DIR |= led4;                                         /*  Set P1.3 to output direction....*/
	                P2OUT &= ~led4;                                 /*  Set led1 off....*/

	                P2DIR |= led5;                                         /*  Set P1.1 to output direction ....*/
	                P2OUT &= ~led5;                                 /* Set led1 off.....*/

	                P1SEL &= ~0x08;                                        /*  Select Port 1 P1.3 (RC5 sensor)....*/
	            P1DIR &= ~0x08;                                        /*  Port 1 P1.3 (RC5 sensor) as input, 0 is input....*/
	                P1REN |= 0x08;
}
volatile unsigned char j1;
void  rc5_operation(void)
{
/* move RC5 data in k ...*/
                 j1= RC5_Read();
                            switch (j1)
                            {
                            case 32:
                            {
                                    P2OUT=~ led1;
                     Delay(1000);
                                    break;
                            }
                            case 33:
                                {
                                        P2OUT=~ led2;
                        Delay(1000);
                                        break;
                                }

                            case 16:
                                {
                                        P2OUT=~ led3;
                                         Delay(1000);
                                        break;
                                }
                            case 17:
                                {
                                        P2OUT=~ led4;
                                         Delay(1000);
                                        break;
                                }
                            case 18:
                                {
                                        P2OUT=~ led5;
                                         Delay(1000);
                                        break;
                                }
                            default:
                                     Delay(1000);
                                    break;

}
}
