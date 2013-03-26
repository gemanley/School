/*
 HW 8; PP4;
 November 10th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

int hydroxide(char string[30])
{
	if(string[strlen(string) - 2] == 'O' && string[strlen(string) - 1] == 'H')
	return 1;
	return 0;
}
int main()
{   
	char input[30];
	printf("Enter the compound: ");
	gets(input);
	if(hydroxide(input))
	printf("This is a hydroxide.\n");
	else
	printf("This is not a hydroxide.\n");
    system("pause");
    return 0;
}
