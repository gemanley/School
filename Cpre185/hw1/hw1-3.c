/*
HW 1; Project 3
August 25th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>

int main()
{
    int temp;
    double hr, min;
    
    printf("How long since the power outage? (H:M) ");
    scanf("%lf:%lf", &hr, &min);
    // Convert minutes to fractions of an hour
    hr = min / 60 + hr;
    // Use the temperature equation from the book
    temp = ((4*(hr*hr)) / (hr + 2)) + 20;
    
    printf("The temperature in the freezer is about %d degrees Celsius.\n", temp);
    system("pause");
    return 0;
}
