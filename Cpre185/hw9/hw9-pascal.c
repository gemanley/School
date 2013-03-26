/*
 HW 9; Pascal;
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

void print(int row[], int len)
{
	int i;
	for(i=20-len; i>0; i--) // print leading spaces
		   printf(" ");
	for(i = 0; i < len; i++)
	{
		printf("%3d ", row[i]);
	}
	printf("\n");
}

void tri(int row1[], int row2[], int num, int row)
{
	int i;
	if(num <= row)
	{
		print(row1, num);
		row2[0] = 1;
		for(i = 1; i < num; i++)
		{
		
			row2[i] = row1[i] + row1[i-1];
			//printf("i: %d, num: %d", i, num);
			//printf("Row1[i]: %d, row1[i-1]: %d, row2[i]: %d\n", row1[i], row1[i-1], row2[i]);
		}
		row2[num] = 1;
		tri(row2, row1, num + 1, row);
	}
}

int main()
{   
	int row;
	int row1[80] = {1}, row2[80] = {1, 1};
	
	printf("What row do you want to display? ");
	scanf("%d", &row);
	tri(row1, row2, 1, row);
    system("pause");
    return 0;
}
