/*
HW 1; Project 11
August 25th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int m;  
    int n;
    float side1, side2;
    float hypotenuse;
    
    printf("Enter a positive integer n: ");
    scanf("%d", &n);
    printf("Enter another that is greater than n: ");
    scanf("%d", &m);
    // Using formulas from the book:
    side1 = m*m - n*n;
    side2 = 2*m*n;
    hypotenuse = m*m + n*n;
    
    printf("The pythagorean triple for those two numbers is %.2f, %.2f, and %.2f.\n", side1, side2, hypotenuse);
    system("pause");
    return 0;
}
