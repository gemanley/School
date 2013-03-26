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
	int i, j = -1;
	double pi = 0;
	for(i = 1; i <= 99; i = i + 2)
	{
		j *= -1;
		pi += j * (1/(double)i);
	}
	printf("Pi is about %f", pi*4);
    system("pause");
    return 0;
}
