/*
 HW 9; PP4;
 November 14th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

char lastChar(char string[60], int i)
{
	if(string[i - 1] == ' ')
	{
		return lastChar(string, i - 1);
	}
	else
	{
		return i - 1; // Why i - 1?  So it won't pickup the '\0'
	}
}
int main()
{   
	char word[60];
	int i;
	printf("Enter your phrase: ");
	gets(word);
	i = strlen(word);
	printf("The last character of that string is %d", lastChar(word, i));
    system("pause");
    return 0;
}
