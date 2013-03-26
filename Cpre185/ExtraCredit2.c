/*
 Exra Credit 2;
 Bulls and Cows;
 November 3rd, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define N 4

int h = 0, tries = 0;

int cows()
{
	int cows;
	printf("Enter the number of cows: ");
	scanf("%d", &cows);
	return cows;
}

int bulls()
{
	int bulls;
	printf("Enter the number of bulls: ");
	scanf("%d", &bulls);
	return bulls;
}

void showNum(int guess[])
{
	int i;
	for(i = 0; i < N; i++)
	{
		printf("%d", guess[i]);
	}
	if(h != 6)
	printf(" is my guess.\n");
	tries++;
}

int main()
{   	
	// Find number set
	int i, j, junk;
	int guess[N], ans[N];

	for(i = 0; i < 10 || h == N - 1; i++)
	{
		for(j = 0; j < N; j++)
		{
			guess[j] = i;
		}
		showNum(guess);
		cows();
		if(bulls())
		{
			ans[h++] = i;
		}
		else
		{
			junk = i;
		}
		if(h == 4)
		break;
	}
	
	// Find correct order
	h = 0;
	for(j = 0; j < N; j++)
	{
		guess[j] = junk;
	}
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			guess[i] = ans[j];
			showNum(guess);
			cows();
			if(bulls() > h)
			{
				guess[h++] = ans[j];
				break;
			}
		}
	}
	h = 6;
	printf("I win!  The number was ");
	showNum(guess);
	printf("It took me %d tries!", tries);
	printf(".\n\n");
    system("pause");
    return 0;
}
