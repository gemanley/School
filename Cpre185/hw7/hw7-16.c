/*
 HW 7; PP16
 October 24th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
void matrix_diff(int mat1[][], int mat2[][], int diffResult[][])
{
	int i, j;
	for (i = 0; i <= 6; i++)
	{
		for (j = 0; j <= 2; j++)
		{
			diffResult[i][j] = mat2[i][j] - mat1[i][j];
		}
	}
}

int main()
{   
	int result[6][2], mat1[6][2], mat2[6][2];
	int i, j;
	for(i = 0; i <= 6; i++)
	{
		for(j = 0; j <= 2; j++)
		{
			printf("Enter mat2[%d][%d]): ", i, j);
			scanf("%d", &mat2[i][j]);
			printf("Enter mat1[%d][%d]): ", i, j);
			scanf("%d", &mat1[i][j]);
		}
	}
	matrix_diff(mat1[6][2], mat2[6][2], result[6][2]);

    system("pause");
    return 0;
}
