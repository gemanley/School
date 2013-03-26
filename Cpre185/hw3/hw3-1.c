/*
HW 3; #1
September 13th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, z1, x2, y2, z2, dist;
    printf("Enter two 3D points:\nX1: ");
    scanf("%lf", &x1);
    printf("Y1: ");
    scanf("%lf", &y1);
    printf("Z1: ");
    scanf("%lf", &z1);
    printf("X2: ");
    scanf("%lf", &x2);
    printf("Y2: ");
    scanf("%lf", &y2);
    printf("Z2: ");
    scanf("%lf", &z2);
    
    dist = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2) + pow((z1 - z2), 2));
    
    printf("The distance between those two points is %f\n", dist);
    system("pause");
    return 0;
}
