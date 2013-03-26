/*
HW 5; PP11
October 4th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int fast_food_billions(int year)
{
    return 33.2 + 16.8*(year - 2005);
}

int main()
{   
    int year;
    do
    {
    printf("Enter a year after 2005 to predict spending(Enter a date before 2005 to quit): ");
    scanf("%d", &year);
    
    if(year < 2005)
            break;
    printf("Americans will spend $%d billion on fast food that year.", fast_food_billions(year));
    }while(1);
    
    system("pause");
    return 0;
}
