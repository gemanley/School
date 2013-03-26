/*
 * GccApplication1.c
 *
 * Created: 9/18/2012 7:35:23 PM
 *  Author: lbreuer
 */ 


#include <stdio.h>

int main(void) {
    unsigned short x = 0b0001000010101010;
    unsigned short y = 0;
    y = pack_ones(x);
    printf("x:%X, y:%X", x, y);
}

unsigned short pack_ones(unsigned short x) {
         for(int i = 0; i < 16; i++) {
                 if(x >> 1 & 0b0000000000000001) {
                      x = x >> 1;
                 }
         }
          y = x;       
}
