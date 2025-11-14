#include<p18f452.h>

void delay(int a);

void main()
{
	TRISB=0;
    PORTB=0;
	for(;;)
{
	PORTB=0x55;
	delay(500);

	PORTB=0xAA;
	delay(500);
}

}

void delay (int a)
{
	while(a--);
}

/*
#include<p18f452.h>

void delay(int);

void main()
{
	PORTB=0;
	TRISB=0;
	for(;;)
{
	PORTB=0x55;
	delay(500);
	PORTB=0xAA;
	delay(500);
}

}

void delay(int a)
{
while(a--);
}

*/
