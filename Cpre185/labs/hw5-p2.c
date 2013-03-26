/*
HW 5; 2
October 4th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>
void printChar(char c, int num)
{
     int i;
     for(i = 0; i < num; i++)
     {
           printf("%c", c);
     }
}

int main()
{   
    int i, j, k;
    scanf("%d", &j);
    for(i = 1; i <= j; i++)
    {
          printChar('*', i);
          printf("\n");            
    }
    for (i = j - 1; i > 0; i--)
    {
        printChar('*', i);
        printf("\n");
    }
    system("pause");
    return 0;
}
