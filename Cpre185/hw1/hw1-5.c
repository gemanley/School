/*
HW 1; Project 5
August 25th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>

int main()
{
    int VTBI, minutes, factor;
    
    printf("Volume to be infused (mL) => ");
    scanf("%d", &VTBI);
    printf("Minutes over which to infuse => ");
    scanf("%d", &minutes);
    // Factor used later to determine mL/hour
    factor = 60 / minutes;
    printf("\nVTBI: %d ml\n", VTBI);
    // Saved space by reusing variables
    VTBI = VTBI * factor;
    printf("Rate: %d ml/hr\n", VTBI);
    system("pause");
    return 0;
}
