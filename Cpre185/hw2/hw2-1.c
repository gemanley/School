/*
HW 2; Project 1
September 7th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>
// Takes a quadratic equation and calculates the real roots
int main()
{
    int a, b, c;
    float x1, x2;
    // Get values
    printf("Enter the corresponding values for ax^2 + bx + c\na: ");
    scanf("%d", &a);
    printf("b: ");
    scanf("%d", &b);
    printf("c: ");
    scanf("%d", &c);
    // Compute roots
    x1 = (-b + sqrt(b*b - 4*a*c))/(2*a);
    x2 = (-b - sqrt(b*b - 4*a*c))/(2*a);
    // Print roots
    printf("The results for the quadratic equation are %.1f and %.1f.", x1, x2);
    
    system("pause");
    return 0;
}
