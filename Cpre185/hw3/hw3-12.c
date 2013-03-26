/*
HW 3; PP 12
September 14th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

void help()
{
     printf("This program will compute the speed of sound in a certain temperature of air.\n");
     printf("Enter the air temperature in Fahrenheit: ");
}

int main()
{   
    double a, T;
    help();
    scanf("%lf", &T);
    a = 1086*sqrt((5*T + 297)/247);
    printf("The speed of sound at that temperature is %.2f\n\n", a);
    system("pause");
    return 0;
}
