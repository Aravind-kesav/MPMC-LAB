#include <P18F458.h>

void main(void)
{
    unsigned char x, y;
    unsigned char mybyte = 0x29;   // Example BCD value = 29 (BCD)

    TRISB = 0x00;   // Set PORTB as output
    TRISC = 0x00;   // Set PORTC as output

    // Extract lower nibble (ones digit)
    x = mybyte & 0x0F;       // 0x29 & 0x0F = 0x09
    PORTB = x | 0x30;        // 0x09 | 0x30 = 0x39 → ASCII '9'

    // Extract higher nibble (tens digit)
    y = (mybyte & 0xF0) >> 4; // (0x29 & 0xF0) >> 4 = 0x02
    PORTC = y | 0x30;          // 0x02 | 0x30 = 0x32 → ASCII '2'

    while(1); // infinite loop
}
