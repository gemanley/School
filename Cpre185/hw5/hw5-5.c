/*
HW 5; PP5
October 4th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int n, digit, i = 0;
    
    printf("Enter up to 10 digits: ");
    scanf("%d", &n);
    while (n>0) 
    {
        digit = n % 10;
        n /= 10;
        printf("%d\n", digit);
        i++;
    }
    system("pause");
    return 0;
}
