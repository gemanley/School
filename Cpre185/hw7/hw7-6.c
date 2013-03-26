/*
 HW 7; PP6;
 October 24th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
double function(double x)
{
	return x*x*sin(x);
}
double trap(double a, double b, int n)
{
	double T, h, term3 = 0;
	int i;
	h = (b - a) / n;
	T = h / 2;
	for ( i = 1; i <= n -1; i++)
	{
		term3 += function(i);
		printf("%f", function(i));
	}
	T *= function(a) + function(b) + 2*term3;
	return T;
}

int main()
{   
	double a, b, T;
	int n;
	printf("Enter a: ");
	scanf("%lf", &a);
	printf("Enter b: ");
	scanf("%lf", &b);
	printf("Enter n: ");
	scanf("%d", &n);
	
	T = trap(a, b, n);
	printf("The approximate area is %f.\n", T);
    system("pause");
    return 0;
}
