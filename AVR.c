// X-NOR gate
#include <avr/io.h>

int main() {
  //  DDRB &= ~((1 << DDB1) | (1 << DDB2));
  //  DDRB |= (1 << DDB3);
  DDRB=0b11111001;
    while (1) {
       
        uint8_t a = (PINB & (1 << PINB1)) >>PINB1;//gives true or false
        uint8_t b = (PINB & (1 << PINB2)) >>PINB2;
        uint8_t y = (a ^ b);                     //xor operation


    
        if (!y)                               //negation of xnor result
        {
            PORTB |= (1 << PORTB3);           //assigning logic high
        } else {
            PORTB &= ~(1 << PORTB3);          // assigning logic low
        }
    }


    return 0;
}
