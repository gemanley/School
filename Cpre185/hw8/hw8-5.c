/*
 HW 8; PP5;
 November 10th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{   
	char word[50];
	printf("Enter your word: ");
	gets(word);
	char lastChar = word[strlen(word) - 1];
	char last2Char = word[strlen(word) - 2];
	if(lastChar == 'y')
	{
		lastChar = '\0';
		strcat(word, "ies");
	}
	else if (lastChar == 's' || (lastChar == 'h' && (last2Char == 'c' || last2Char == 's')))
	{
		lastChar = '\0';
		strcat(word, "es");
	}
	else
	strcat(word, "s");
	printf("The pluralized word is %s.\n", word);
    system("pause");
    return 0;
}
