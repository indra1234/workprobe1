
#ifndef P89V51RD2_H_
#define P89V51RD2_H_

#include <reg52.h>
sbit led1=P2^0;
sbit led2=P2^1;
sbit led3=P2^2;
sbit led4=P2^3;
sbit led5=P2^4; 
sbit    BUZZER=P3^3;
sbit	RC5=P3^2;
unsigned char 	RC5_Read();
void Delay(unsigned int tic); 
#endif
void Delay(unsigned int tic)
{
	char i;
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
void Delay_RC5()
{
	char i=170;
	while(i!=0)
	{
	i--;
	}		
}
unsigned char RC5_Read()
{
	unsigned char temp=0,count;
	RC5=1;
	/// wait 3.5 MS to ensure the channel is free ///////////////
	for(count=0;count<6;count++)
	{
		Delay_RC5();
		if(RC5==0)
		return	255; // if not free, return 0 //////////
	} 

	count=130;
  	while(count!=0 && RC5==1)
	{
		Delay_RC5();
		count--;
	}
	if(count==0)
	return	255;	
	while(RC5==0);


	for(count=12;count!=0;count--)
	{
		Delay_RC5();
		if(count<7)
		{
		temp= (temp<<1)|RC5;		
		}
		if(RC5==1)
		while(RC5==1);
		else
		while(RC5==0);
	}  
	return temp;
}
	