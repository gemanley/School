/*
 HW 9; PP2;
 November 16th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void convert(char input[90])
{
	int i, j = 0;
	for(i = 0; i < strlen(input); i++)
	{
		if(isalpha(input[i]))
		{
			if(isupper(input[i]))
			{
				input[i] = tolower(input[i]);
			}
			input[j++] = input[i];
		}
	}
	input[i + 1] = ' ';
	input[j] = '\0';
}

int palindrome(char phrase[90], int i, int j, int correct)
{
	//printf("i: %d, j: %d, phrase[i]: %c, phrase[j]: %c\n", i, j, phrase[i], phrase[j]);
	if(i <= j){
	if(phrase[i] == phrase[j])
	{
		return palindrome(phrase, i+1, j-1, correct);
	}
	else
	{
		correct = 0;
		return correct;
	}}
	return 1;
}

int main()
{   
	char phrase[90];
	printf("Enter the word or phrase: ");
	gets(phrase);
	convert(phrase);
	int start = 0;
	int end = strlen(phrase);
	if(palindrome(phrase, start, end - 1, 1))
	{
		printf("This is a palindrome.\n");
	}
	else
	{
		printf("This isn't a palindrome.\n");
	}
    system("pause");
    return 0;
}
