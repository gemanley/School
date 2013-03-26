/*
HW 4; PP 1
September 30th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    float disc = 0;
    char type;
    double total;
    printf("Enter the total: ");
    scanf("%lf", &total);
    printf("Is the customer a teacher? (Y/N): ");
    fflush(stdin);
    scanf("%c", &type);
    
    
    printf("Total purchases\t\t\t$%10.2f\n", total);
    if (type == 'y' || type == 'Y')
    {
             if (total > 100)
                 disc = .12;
             else
                 disc = .1;
             printf("Teacher's discount (12%%)\t%11.2f\n", total*disc);
             printf("Discounted total\t\t%11.2f\n", total - total*disc);
    }
    printf("Sales tax (5%%)\t\t\t%11.2f\n", .05*(total - total*disc));
    printf("Total\t\t\t\t$%10.2f\n", total - total*disc + .05*(total - total*disc));
    system("pause");
    return 0;
}
