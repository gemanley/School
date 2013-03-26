/*
HW 4; PP 8
September 30th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int choice;
    double grams, miles;
    printf("(1) Carbon monoxide\n(2) Hydrocarbons\n(3) Nitrogen oxides\n(4) Nonmethane hydrocarbons\nEnter pollutant number>> ");
    scanf("%d", &choice);
    printf("Enter number of grams emitted per mile>> ");
    scanf("%lf", &grams);
    printf("Enter odometer reading>> ");
    scanf("%lf", &miles);
    if (miles < 50000)
    {
    switch (choice)
    {
           case 1:
                if(grams > 3.4)
                         printf("Emissions exceed permitted level of 3.4 grams/mile.\n");
                break;
           case 2:
                if(grams > .31)
                         printf("Emissions exceed permitted level of .31 grams/mile.\n");
                break;
           case 3:
                if(grams > .4)
                         printf("Emissions exceed permitted level of .4 grams/mile.\n");
                break;
           case 4:
                if(grams > .25)
                         printf("Emissions exceed permitted level of .25 grams/mile.\n");
                break;
           default:
                   printf("Not a valid choice.\n");
    }
                
    }
    else
    {
        switch (choice)
    {
           case 1:
                if(grams > 4.2)
                         printf("Emissions exceed permitted level of 4.2 grams/mile.\n");
                break;
           case 2:
                if(grams > .39)
                         printf("Emissions exceed permitted level of .39 grams/mile.\n");
                break;
           case 3:
                if(grams > .5)
                         printf("Emissions exceed permitted level of .5 grams/mile.\n");
                break;
           case 4:
                if(grams > .31)
                         printf("Emissions exceed permitted level of .31 grams/mile.\n");
                break;
           default:
                   printf("Not a valid choice.\n");
    }
    }
    system("pause");
    return 0;
}
