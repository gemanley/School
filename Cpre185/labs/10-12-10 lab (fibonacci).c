/*
Lab 1 - Fibonacci
October 4th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int n = 0, n1 = 1, i, digit;
    scanf("%d", &digit);
    for(i = 0; i < digit; i++)
    {
            n = n + n1;
            n1 = n1 + n;
    }
    system("pause");
    return 0;
}
