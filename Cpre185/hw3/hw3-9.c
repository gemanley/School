/*
HW 3; PP 9
September 14th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

void help()
{
     printf("This program calculates the cost of each container and the");
     printf(" total cost of producing all of the containers.\n");
     printf("Enter the radius of the container: ");
}

double area(double r, double h)
{
       double t_area, sideArea, bottomArea;
       bottomArea = M_PI * r * r;
       sideArea = 2 * M_PI * r * h;
       t_area = bottomArea + sideArea;
       return(t_area);
}

int main()
{   
    double radius, height, cost, quantity, totCost;
    help();
    
    scanf("%lf", &radius);
    printf("Enter the height of the container: ");
    scanf("%lf", &height);
    printf("Enter the cost per square centimeter: $");
    scanf("%lf", &cost);
    printf("How many containers are you going to make? ");
    scanf("%lf", &quantity);
    
    totCost = cost*area(radius, height);
    
    printf("\nThe cost to make each container is $%.2f.\n", totCost);
    printf("The cost to make all of the containers is $%.2f.\n\n", quantity*totCost);
    
    system("pause");
    return 0;
}
