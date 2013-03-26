/*
Lab 3
September 7th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
double paint(double lngth, double wdth, double ht)
{
       double area;
       
       area = (lngth * ht) * 2;
       area = area + (wdth * ht) * 2;
       area = area + (lngth * wdth) * 2;
       
       return area;
}
int main()
{
    double paint1, lngth, wdth, ht;
    
    printf("What are the dimensions of the room?\n");
    printf("Length: ");
    scanf("%lf", &lngth);
    printf("Width: ");
    scanf("%lf", &wdth);
    printf("Height: ");
    scanf("%lf", &ht);
    
    paint1 = paint(lngth, wdth, ht);
    
    printf("You will need %f ft of paint.", paint1*.01);
    system("pause");
    return 0;
}
