/*
 HW 6; PP8
 October 18th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>

int main()
{   
    double current[13], prev[13];
    int i;
    current[12] = 0;
    prev[12] = 0;
    
    printf("Enter both years' rainfall (Starting from January, current first, separated by a space): ");
    for(i = 0; i < 12; i++)
    {
     scanf("%lf %lf", &current[i], &prev[i]);
    }
    printf("           Jan   Feb   Mar   Apr   May   Jun   Jul   Aug   Sep   Oct   Nov   Dec");
    printf("\nThis year  ");
    for(i = 0; i < 12; i++)
    {
          printf("%3.1f   ", current[i]);
          current[12] += current[i];
    }
    printf("\nLast year  ");
    for(i = 0; i < 12; i++)
    {
          printf("%3.1f   ", prev[i]);
          prev[12] += prev[i];
    }
    printf("\nTotal rainfall this year: %.1f", current[12]);
    printf("\nTotal rainfall last year: %.1f", prev[12]);
    printf("\nAverage monthly rainfall for this year: %.1f", current[12]/12);
    printf("\nAverage monthly rainfall for last year: %.1f\n", prev[12]/12);
    system("pause");
    return 0;
}
