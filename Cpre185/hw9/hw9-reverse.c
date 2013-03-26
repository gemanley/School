/*
 HW 9; Reverse;
 November 10th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char reverse(char string[90], int i, int j)
{
	char temp;
	if(i<j)
	{
		temp = string[i];
		string[i] = string[j];
		string[j] = temp;
		return reverse(string, i + 1, j - 1);
	}
}

int main()
{   
	char string[90];
	printf("Enter the string you want to reverse: ");
	gets(string);
	reverse(string, 0, strlen(string) - 1);
	printf("The reversed string is \"%s\"\n", string);
    system("pause");
    return 0;
}
