/*
 HW 7; PP3;
 October 24th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>

int main()
{   
	double amount, C, r, H;
	int y;
	
	printf("Enter the initial amount: ");
	scanf("%lf", &amount);
	C = pow(2.71828, -.693);
	H = 5.272;
	printf("\tAmount remaining");
	
	for(y = 0; y <= 5; y++)
	{
		r = amount * pow(C, (y/H));
		printf("\nYear %d: %f", y, r);
	}

    system("pause");
    return 0;
}
