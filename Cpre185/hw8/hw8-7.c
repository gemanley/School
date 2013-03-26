/*
 HW 8; PP7;
 November 11th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{   
	int i, j, k = 0;
	char input[90], output[90];
	printf("Input: ");
	gets(input);
	for(i = strlen(input); i >= 0; i--)
	{
		if(input[i] == ' ' || i == 0)
		{
			j = i;
			if(i != 0)
			j = i + 1;
			while(input[j] != ' ' && input[j] != '\0')
			{
				output[k++] = input[j++];
			}
			output[k++] = ' ';
		}
	}
	output[k] = '\0';
	printf("Reversed: %s\n\n", output);
    system("pause");
    return 0;
}
