/*
HW 2; Project 3
September 7th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>

int main()
{
    int num;
    
    printf("Enter a number to find the multiplication table for: ");
    scanf("%d", &num);
    printf(" 1 x %d = %3d\n", num, num*1);
    printf(" 2 x %d = %3d\n", num, num*2);
    printf(" 3 x %d = %3d\n", num, num*3);
    printf(" 4 x %d = %3d\n", num, num*4);
    printf(" 5 x %d = %3d\n", num, num*5);
    printf(" 6 x %d = %3d\n", num, num*6);
    printf(" 7 x %d = %3d\n", num, num*7);
    printf(" 8 x %d = %3d\n", num, num*8);
    printf(" 9 x %d = %3d\n", num, num*9);
    printf("10 x %d = %3d\n", num, num*10);
    system("pause");
    return 0;
}
