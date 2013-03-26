/*
HW 1; Project 1
August 25th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>

int main()
{
    double m1, m2, m3, cash;
    /* Accept user input */
    printf("MILAGE REIMBURSEMENT CALCULATOR\nEnter beginning odometer reading=> ");
    scanf("%lf", &m1);
    printf("Enter ending odometer reading=> ");
    scanf("%lf", &m2);
    /* Find difference between readings */
    m3 = m2 - m1;
    /* Find reimbursement at 35 cents/mile */
    cash = .35 * m3;
    
    printf("You traveled %.1f miles.  At $0.35 per mile, your reimbursement is $%.2f.\n", m3, cash);
    system("pause");
    return 0;  
}
