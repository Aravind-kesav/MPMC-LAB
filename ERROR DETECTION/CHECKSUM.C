#include<p18f452.h>
void main(void) {
    unsigned char mydata[4] = {0x25, 0x62, 0x3F, 0x52}; 
    unsigned char checksum = 0;
    unsigned char i;
    unsigned int sum = 0;

    TRISC = 0x00; 						// PORTC as output (to show data)
    TRISB = 0x00; 						// PORTB as output (to show checksum)

    // Step 1: Add all data bytes
    for(i = 0; i < 4; i++) {
        PORTC = mydata[i];   					// show each byte on PORTC
        sum += mydata[i];
    }

    // Step 2: Take 2’s complement of sum
    checksum = (unsigned char)(~sum + 1);

    								// Step 3: Output checksum on PORTB
    PORTB = checksum;

    }

