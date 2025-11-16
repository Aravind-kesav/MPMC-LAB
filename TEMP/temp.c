#include "LPC214x.h"
int ReadADC(char ChannelNumber);
int main(void)
{
int a;
unsigned char Channel = 1, t[7];
PINSEL1 = 0x01000000; // Select pin function for ADC (e.g., AD0.1)
InitializeLCD(); // Initialize LCD
DisplayLCD(0, " Room Temperature"); // Display message on LCD
while (1)
{
a = ReadADC(Channel); // Read ADC value from specified channel
// Convert integer value to string format for display
t[0] = a / 100 + '0';
a -= (a / 100) * 100;
t[1] = a / 10 + '0';
t[2] = '.';
t[3] = a % 10 + '0';
t[4] = 'c';
t[5] = 0;
DisplayLCD(1, t); // Display temperature value on LCD
LCDDelay1600(); // Delay for LCD refresh
}
}
int ReadADC (char ChannelNumber)
{
int val, ch;
ch = 1 << ChannelNumber; // Select the appropriate channel
AD0CR = 0x00210400 | ch; // Configure ADC (PCLK/4, enable ADC)
AD0CR |= 0x01000000; // Start conversion by setting the START bit
// Wait for conversion to complete (Done bit set in AD0DR1)
do
{
val = AD0DR1; // Read from the AD0DR1 register
}
while ((val & 0x80000000) == 0); // Wait for the DONE bit (bit 31)
val = (val >> 6) & 0x03FF; // Extract the 10-bit ADC result
AD0CR &= ~0x01000000; // Stop conversion by clearing the START bit
return val; // Return the ADC value
}
