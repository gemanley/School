/*
 HW 9; PP3;
 November 17th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int func(int x)
{
	if(x <= 0)
	{
		return 0;
	}
	else
	{
		return func(x - 1) + 2;
	}
}

int main()
{   
	int x;
	printf("Enter a value for x: ");
	scanf("%d", &x);
	printf("%d", func(x));
    system("pause");
    return 0;
}
