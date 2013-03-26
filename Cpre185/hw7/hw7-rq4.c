/*
 HW 7; RQ4
 October 24th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
double sum(int n, double x)
{
	int i;
	double sum = 0;
	for (i = 1; i <= n; i++)
	{
		sum += pow(x, i) / i;
	}
	return sum;
}
int main()
{   
	int n;
	double x;
	printf("Enter x and n: ");
	scanf("%lf", &x);
	scanf("%d", &n);
    printf("%f", sum(n, x));

    system("pause");
    return 0;
}
