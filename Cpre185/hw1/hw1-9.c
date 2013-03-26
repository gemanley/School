/*
HW 1; Project 9
August 25th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>

int main()
{
    /*
    h: house
    y: yard
    l: length
    w: width
    a: area
    */
    double hl, hw, yl, yw, ya, ha, time;
    
    printf("Enter the length and width of the yard (ft): ");
    scanf("%lf%lf", &yl, &yw);
    printf("Enter the length and width of the house (ft): ");
    scanf("%lf%lf", &hl, &hw);
    
    // Basic formulas to find area
    ha = hl * hw;
    ya = yl * yw;
    ya = ya - ha;
    time = ya / 2;
    
    printf("Mowing at 2 sq ft/sec, it would take %.2f seconds to mow the lawn.\n", time);
    system("pause");
    return 0;
}
