/*
 HW 8; PP8;
 November 10th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

void suffix(char output[30], char input[2][30])
{
	int len1 = strlen(input[0]), len2 = strlen(input[1]);
	int i = 0, j;
	while(input[0][len1] == input[1][len2] && len1 >= 0 && len2 >= 0)
	{
		len1--;
		len2--;
		i++;
	}
	for(j = 0; j < i; j++)
	{
		output[j] = input[0][len1 + 1];
		len1++;
	}
	output[j] = '\0';
}

int main()
{   
	char a[2][30], output[30];
	printf("Enter your first word: ");
	gets(a[0]);
	printf("Enter your second word: ");
	gets(a[1]);
	suffix(output, a);
	if(strcmp(output, ""))
	printf("The common suffix is \"%s\"\n", output);
	else
	printf("There is no common suffix.\n");
    system("pause");
    return 0;
}
