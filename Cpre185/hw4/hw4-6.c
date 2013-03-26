/*
HW 4; PP 6
September 29th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    double x, y;
    printf("Enter the X coordinate: ");
    scanf("%lf", &x);
    printf("Enter the Y coordinate: ");
    scanf("%lf", &y);
    
    if (y == 0 && x == 0)
          printf("(%.1f, %.1f) is on the origin\n", x, y);
    else if (y == 0)
         printf("(%.1f, %.1f) is on the x-axis\n", x, y);
    else if (x == 0)
         printf("(%.1f, %.1f) is on the y-axis\n", x, y);
    else if (x > 0)
    {
          if (y > 0)
             printf("(%.1f, %.1f) is in quadrant I\n", x, y);
          else if (y < 0)
             printf("(%.1f, %.1f) is in quadrant IV\n", x, y);
    }
    else if (x < 0)
    {
         if (y > 0)
             printf("(%.1f, %.1f) is in quadrant II\n", x, y);
          else if (y < 0)
             printf("(%.1f, %.1f) is in quadrant III\n", x, y);
    }
    system("pause");
    return 0;
}
