/*
 HW 7; PP14
 October 24th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>

void get_poly( double coeff[], int* degreep)
{
	int i;
	for (i = 0; i <= degreep; i++)
	{
		scan("%lf", coeff[i]);
	}
}
double eval_poly ( const double coeff[], int degree, double x)
{
	int i;
	double sum = 0;
	for(i = 0; i <= degree; i++)
	{
		sum += coeff[degree - i] * pow(x, i);
	}
	return sum;
}
	
int main()
{   
	int degree;
	printf("Enter the degree of the polynomial: ");
	scanf("%d", &degree);
	printf("Enter each coefficient: ");
	double coeff[degree];
	get_poly(coeff[degree], degree);
	double x;
	printf("Enter the value for x: ");
	scanf("%lf", &x);
	eval_poly(coeff[degree], degree, x);

    system("pause");
    return 0;
}
