/*
 HW 9; PP4;
 November 17th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int one(char input[], int i, int j)
{
	if(i<j){
	printf("{%c}\n", input[i]);
	return one(input, i + 1, j);}
}

int two(char input[], int i, int j)
{
	int k;
	if(i<j){
	for(k = i; k < j; k++)
	{
		if(input[i]!=input[k])
		printf("{%c, %c}\n", input[i], input[k]);
	}
	return two(input, i + 1, j);}
}

int three(char input[], int i, int j)
{
	if(i<j)
	{
		int k, l;
		for(k = i; k < j; k++)
		{
			if(input[i]!=input[k])
			for(l = k; l < j; l++)
			{
				if(input[k]!=input[l] && input[i]!=input[l])
				printf("{%c, %c, %c}\n", input[i], input[k], input[l]);
			}
		}
		return three(input, i + 1, j);
	}
}

int main()
{   
	char input[90];
	printf("Hey, enter your letters: ");
	gets(input);
	int len = strlen(input);
	printf("\none_ele_subs\n(\"%s\")\n\n", input);
	one(input, 0, len);
	printf("\ntwo_ele_subs\n(\"%s\")\n\n", input);
	two(input, 0, len);
	printf("\nthree_ele_subs\n(\"%s\")\n\n", input);
	three(input, 0, len);
    system("pause");
    return 0;
}
