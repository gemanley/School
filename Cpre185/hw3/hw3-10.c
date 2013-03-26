/*
HW 3; PP 10
September 14th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

double celsius_at_depth(double depth)
{
       double C = depth*10 + 20;
       return(C);
}

double fahrenheit(double C)
{
       double F = C*1.8 + 32;
       return(F);
}

int main()
{
    double depth;
    
    printf("What is the depth in kilometers?\n");
    scanf("%lf", &depth);
    printf("The temperature at that depth in Celsius is %.2f.\n", celsius_at_depth(depth));
    printf("That same temperature in Fahrenheit is %.2f.\n", fahrenheit(celsius_at_depth(depth)));
    system("pause");
    return 0;
}
