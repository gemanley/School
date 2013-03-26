/*
 HW 7; PP15
 October 24th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
void get_grid(int grid[][4])
{
	int i, j;
	for(i = 0; i <= 2; i++)
	{
		for(j = 0; j <= 3; j++)
		{
			printf("Sector %d, %d: ", i, j);
			scanf("%d", &grid[i][j]);
		}
	}
}

void display_grid(int grid[][4])
{
	int i, j;
	for(i = 0; i <= 2; i++)
	{
		for(j = 0; j <= 3; j++)
		{
			printf("%d\t", grid[i][j]);
		}
		printf("\n");
	}
}
int power_ok(int grid[][4])
{
	int i, j, tot = 0;
	for(i = 0; i <= 2; i++)
	{
		for(j = 0; j <= 3; j++)
		{
			tot += grid[i][j];
		}
	}
	if(tot == 12)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void where_off(int grid[][4])
{
	int i, j;
	for (i = 0; i <= 2; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			if(grid[i][j] == 0)
			{
				printf("Power is off in Sector (%d, %d).\n", i, j);
			}
		}
	}
}

int main()
{   
	int grid[3][4];
	printf("Enter the value of the following sectors.\n");
	get_grid(grid);
	display_grid(grid);
	if(power_ok(grid))
	{
		printf("Power is on throughout the grid.\n");
	}
	else
	{
		where_off(grid);
	}

    system("pause");
    return 0;
}
