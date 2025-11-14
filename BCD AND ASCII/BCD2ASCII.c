#include <P18F458.h>   // Header file for PIC18F458

void main(void)
{
    unsigned char bcdbyte;   // Variable to store final BCD value
    unsigned char w = '4';   // ASCII value for character '4' (0x34)
    unsigned char z = '7';   // ASCII value for character '7' (0x37)

    TRISB = 0x00;            // Configure PORTB as output

    // --- ASCII to BCD conversion ---
    w = w & 0x0F;            // Mask upper nibble → get lower nibble (4)
    w = w << 4;              // Move 4 to upper nibble position → 0x40
    z = z & 0x0F;            // Mask upper nibble → get lower nibble (7)

    bcdbyte = w | z;         // Combine both nibbles → 0x47 (BCD for 47)

    PORTB = bcdbyte;         // Output the BCD result to PORTB

    while(1);                // Infinite loop to hold output
}
