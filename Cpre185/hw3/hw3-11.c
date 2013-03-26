/*
HW 3; PP 11
September 14th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

double speeds_ratio(double max, double min)
{
       double ratio = pow((max/min), (1./5.));
       return(ratio);
}
       
int main()
{
    double max, min;
    printf("Enter a maximum speed and a minimum speed.  Max: ");
    scanf("%lf", &max);
    printf("Min: ");
    scanf("%lf", &min);
    
    printf("The ratio between successive speeds of a six-speed gearbox");
    printf(" with maximum speed %.2f and minimum speed %.2f", max, min);
    printf(" rpm is %.2f.\n\n", speeds_ratio(max, min));
    system("pause");
    return 0;
}
