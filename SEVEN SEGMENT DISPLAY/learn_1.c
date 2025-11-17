#include<p18f452.h>
void delay(int);
void main()
{
   int i,j;
	//int a[8]={128,121,121,121,128,61,57,120}; //for .GCTEEE
	int a[8]={61,63,63,63,56,62,57,182}; //for GOODLUCK
	int b[8] = {8,4,2,1,8,4,2,1};
    
	TRISB=0;
    TRISD=0;

	while(1)
	{
	for(j=0;j<2000;j++)
	{
	for(i = 0; i<4;i++)
	{
   	PORTB=a[i];
	PORTD=b[i];
	delay(200);
    	}
	}
	PORTD=0;
	delay(62000);

	for(j=0;j<2000;j++)
	{
	for(i=4;i<8;i++)
	{
   	PORTB=a[i];
	PORTD=b[i];
	delay(200);
    }
	}
	PORTD=0;
	delay(62000);
	}
}

void delay(int j)
{
while(j--);
}

