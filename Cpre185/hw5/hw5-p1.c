/*
HW 5; 1
October 4th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int i, j;
    printf("0   1  2  3  4  5  6  7  8  9\n_________________________________");
    for(i = 1; i <= 9; i++)
    {
          printf("\n");
          printf("%d|", i);
            for(j = 1; j <= 9; j++)
            {
                    printf("%3d", j*i);
            }
    }
    printf("\n");
    system("pause");
    return 0;
}
