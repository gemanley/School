/*
HW 4; PP 3
September 29th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int heading;
    printf("Enter a heading: ");
    scanf("%d", &heading);
    if (heading > 360)
       heading = heading % 360;
    printf("Your bearing is: ");
    if (heading < 0)
       heading = 360 - heading;
    else if (heading < 90 || heading > 270)
    {
       printf("North ");
       if (heading > 270)
          printf("%d degrees West\n", 360 - heading);
       else
           printf("%d degrees East\n", heading);
    }
    else
    {    
        printf("South ");
        if (heading > 180)
          printf("%d degrees West\n", heading - 180);
       else
           printf("%d degrees East\n", 180 - heading);
    }
    
    system("pause");
    return 0;
}
