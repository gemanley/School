/*
Distance Formula
September 7th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

double dist(double x1, double x2, double y1, double y2)
{
       double dist;
       dist = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
       return dist;
}

int main()
{
    double x1, x2, y1, y2, howfar;
    printf("Enter the two points.\nX1: ");
    scanf("%lf", &x1);
    printf("X2: ");
    scanf("%lf", &x2);
    printf("Y1: ");
    scanf("%lf", &y1);
    printf("Y2: ");
    scanf("%lf", &y2);
    
    howfar = dist(x1, x2, y1, y2);
    
    printf("There are %f units between those points.", howfar);
    system("pause");
    return 0;
}
