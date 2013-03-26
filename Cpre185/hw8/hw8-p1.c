/*
 HW 8; P1;
 November 2nd, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int strtoint(char str[20])
{
	return(atoi(str));
}

double strtodouble(char str[20])
{
	return(atof(str));
}

int main()
{   
	printf("%d\n", strtoint("49"));
	printf("%f\n", strtodouble("49.958"));
    system("pause");
    return 0;
}
