#include<p18f452.h>

void delay(unsigned int j);

void main()
{
    unsigned char i;
    TRISB = 0x00;  // Set PORTB as output
    PORTB = 0x00;  // Turn off all LEDs initially

    while(1)
    {
        // Blink LEDs one by one
        for(i = 0; i < 4; i++)
        {
            PORTB = (1 << i);  // Shift 1 to position i (RB0 to RB3)
            delay(50000);
        }
        
        // Turn off all LEDs
        PORTB = 0x00;
        delay(50000);
    }
}

void delay(unsigned int j)
{
    while(j--);
}
