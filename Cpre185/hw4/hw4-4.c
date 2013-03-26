/*
HW 4; PP 4
September 29th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    char color;
    printf("Enter the first letter of the color: ");
    scanf("%c", &color);
    if (color == 'O' || color == 'o')
       printf("Ammonia is in the orange container.\n");
    else if (color == 'B' || color == 'b')
       printf("Carbon monoxide is in the brown container.  There is no blue container.\n");
    else if (color == 'G' || color == 'g')
       printf("Oxygen is in the green container.\n");
    else if (color == 'Y' || color == 'y')
       printf("Hydrogen is in the yellow container.\n");
    else
        printf("Contents unknown.\n");
    
    system("pause");
    return 0;
}
