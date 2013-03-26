/*
 HW 10; RQ 5;
 November 21st, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	char address[6];
	char city[40];
	char state[20];
	char zip[10];
} address;

typedef struct
{
	char description[1023];
	char time[10];
	char days[80];
} Class;

typedef struct
{
	float gpa;
	char major[80];
	address address;
	Class Class[6];
} studentA;

int main()
{   
	struct studentA;
	printf("See source for the data structure.\n");
    system("pause");
    return 0;
}
