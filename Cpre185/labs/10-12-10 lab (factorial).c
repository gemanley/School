/*
Lab 1 - Factorial
October 4th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int n, fact;
    scanf("%d", &n);
    int i = n;
    while(i >= 1)
    {
            fact = n*(n-i);
    }
    printf("%d", fact);
    system("pause");
    return 0;
}
