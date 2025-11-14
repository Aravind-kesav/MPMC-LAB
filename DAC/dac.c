#include "LPC214x.h"

void InitializeDAC(void);

void main(void)
{
	long c;
	InitializeDAC();
	while(1)
	{
		DACR = 0x00;
		for(c=0;c<0xf0000;c++);
		DACR = 0X0000ffc0;
		for(c=0;c<0xf0000;c++);
	}
}

void InitializeDAC()
{
	PINSEL1 = 0x00080000;
	
}