#include<16F877A.h>

#use delay(clock=20000000)
#use rs232(baud=19200, xmit=PIN_C6, rcv=PIN_C7)

void busycheck();

unsigned int array[19]={"Vi Microsystems"};
unsigned char array1[] = {"VPUT-01"};
unsigned char array2[] = {"Embedded Trainer"};
unsigned char a,i,b;

void main()
{

        output_low(PIN_B3);
        output_high(PIN_B1);

        busycheck();
        output_d(0x38);         /* Entry mode set */
        output_high(PIN_B3);
        output_low(PIN_B3);

        busycheck();
        output_d(0x06);         /* function set */
        output_high(PIN_B3);
        output_low(PIN_B3);

        busycheck();
        output_d(0x01);         /* clear display */
        output_high(PIN_B3);
        output_low(PIN_B3);

        busycheck();
        output_d(0x0c);         /* cursor on */
        output_high(PIN_B3);
        output_low(PIN_B3);

        busycheck();
        output_d(0x82);         /* starting address */
        output_high(PIN_B3);
        output_low(PIN_B3);

        for (i=0;i<15;i++)
        {
                busycheck();
                output_d(0x01);
                output_low(PIN_B1);
                output_high(PIN_B1);

                b=array[i];
                output_d(b);
                output_high(PIN_B3);
                output_low(PIN_B3);
        }

	 	busycheck();
        output_d(0xc6);         /* starting address */
        output_high(PIN_B3);
        output_low(PIN_B3);

		for (i=0;i<7;i++)
        {
                busycheck();
                output_d(0x01);
                output_low(PIN_B1);
                output_high(PIN_B1);

                b=array1[i];
                output_d(b);
                output_high(PIN_B3);
                output_low(PIN_B3);
        }


		busycheck();
        output_d(0x96);         /* starting address */
        output_high(PIN_B3);
        output_low(PIN_B3);

		for (i=0;i<16;i++)
        {
                busycheck();
                output_d(0x01);
                output_low(PIN_B1);
                output_high(PIN_B1);

                b=array2[i];
                output_d(b);
                output_high(PIN_B3);
                output_low(PIN_B3);
        }

		busycheck();
        output_d(0xd4);         /* starting address */
        output_high(PIN_B3);
        output_low(PIN_B3);

		for (i=0;i<20;i++)
        {
                busycheck();
                output_d(0x01);
                output_low(PIN_B1);
                output_high(PIN_B1);

                
                output_d('-');
                output_high(PIN_B3);
                output_low(PIN_B3);
        }

	
stop:
        goto stop;
}


void busycheck()
{
        output_d(0x02);
        output_low(PIN_B1);
        output_high(PIN_B1);
        delay_ms(2);
busy:
        output_high(PIN_B3);
        output_low(PIN_B3);
        a=input_d();
        if ((a&0x80)==0x80)
                goto busy;
        output_d(0x0);
        output_low(PIN_B1);
        output_high(PIN_B1);
        delay_us(10);
}
