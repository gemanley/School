/*
 Midterm 2
 October 26th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>


int main()
{   
	double x[2], y[2], Q[4], R[3];
	double rx, ry;
	printf("Please enter x1: ");
	scanf("%lf", &x[0]);
	printf("Please enter x2: ");
	scanf("%lf", &x[1]);
	printf("Please enter y1: ");
	scanf("%lf", &y[0]);
	printf("Please enter y2: ");
	scanf("%lf", &y[1]);
	printf("Please enter x: ");
	scanf("%lf", &rx);
	printf("Please enter y: ");
	scanf("%lf", &ry);
	printf("Please enter Q11=f(x1, y1): ");
	scanf("%lf", &Q[0]);
	printf("Please enter Q12=f(x1, y2): ");
	scanf("%lf", &Q[1]);
	printf("Please enter Q21=f(x2, y1): ");
	scanf("%lf", &Q[2]);
	printf("Please enter Q22=f(x2, y2): ");
	scanf("%lf", &Q[3]);
	
	R[0] = (rx - x[0]) / (x[1] - x[0]) * Q[2];
	R[0] += (x[1] - rx) / (x[1] - x[0]) * Q[0];
	
	R[1] = (ry - y[0]) / (y[1] - y[0]) * Q[1];
	R[1] += (y[1] - ry) / (y[1] - y[0]) * Q[3];
	
	printf("The interpolated value of the function at R1=(x, y1) is %.2f\n", R[0]);
	printf("The interpolated value of the function at R2=(x, y2) is %.2f\n", R[1]);
	
	R[2] = (ry - y[0]) / (y[1] - y[0]) * R[0];
	R[2] += (y[1] - ry) / (y[1] - y[0]) * R[1];
	
	printf("The interpolated value of the function at (x=%f, y=%f) is %.2f\n", rx, ry, R[2]);
    system("pause");
    return 0;
}
