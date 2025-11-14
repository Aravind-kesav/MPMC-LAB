#include<p18f452.h>
void main(void) {

unsigned char mydata[4] = {0x25, 0x62, 0x3F, 0x52}; 
unsigned char checksum = 0xFF; 				// From previous calculation

    unsigned char i;
    unsigned int sum = 0;

    TRISD =0; 						// PORTD output (to show result)

    							// Step 1: Add all data + checksum
    for(i = 0; i < 4; i++) {
        sum += mydata[i];
    }
    sum += checksum;

    							// Step 2: Check if result == 0
    if((unsigned char)sum == 0) {
        PORTD = 'G';   					// Send ASCII 'G' ? GOOD
   } else {
        PORTD = 'B';   					// Send ASCII 'B' ? BAD
    }

}