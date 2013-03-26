/*
HW 6; PP4
October 17th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int x[12], i, step1 = 0, step2 = 0, chdigit;
    printf("Enter the barcode: ");
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7], &x[8], &x[9], &x[10], &x[11]);
    for(i = 0; i < 12; i+=2)
    {
          step1 += x[i];
    }
    step1 *= 3;
    printf("Step 1: %d\n", step1);
    for(i = 1; i<=10; i += 2)
    {
          step2 += x[i];
    }
    step2 += step1;
    printf("Step 2: %d\n", step2);
    chdigit = step2 % 10;
    if (chdigit != 0)
       chdigit = 10 - chdigit;
    if(x[11] == chdigit)
             printf("validated\n");
    else
        printf("error in barcode\n");
             
    
    system("pause");
    return 0;
}
