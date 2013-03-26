/*
HW 6; PP4
October 13th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int x[20], y[20], z[20], n = 0, i = 0, tot = 0, j;
    x[0] = 0;
    y[0] = 0;
    
    while (x[n-1] != -1 || n == 20)
    {
          printf("Enter the first data set (enter -1 to quit): ");
          scanf("%d", &x[n]);
          n++;
    }
    for (i = 0; i < n - 1; i++)
    {
          printf("Enter the second data set: ");
          scanf("%d", &y[i]);
    }
    printf("|        x |        y |         z |\n");
    printf("|----------|----------|-----------|\n");
    for(j = 0; j < n - 1; j++)
    {
          z[j] = x[j]*y[j];
          tot += z[j];
          printf("| %7d | %7d | %7d\n", x[j], y[j], z[j]);
    }
    printf("\nThe square root of the sum of column z is %f\n", sqrt(tot));
    
    system("pause");
    return 0;
}
