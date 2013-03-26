/*
 HW 8; PP1;
 November 2nd, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
#include <string.h>

void deblank(char in[50], char out[50])
{
	int i, j = 0;
	for(i = 0; i < strlen(in); i++)
	{
		if(in[i] != ' ')
		out[j++] = in[i];
	}
	out[j] = '\0';
}

int main()
{   
	char in[50], out[50];
	printf("Enter the string to deblank: ");
	gets(in);
	deblank(in, out);
	printf("The deblanked string is \"%s\"\n", out);
    system("pause");
    return 0;
}
