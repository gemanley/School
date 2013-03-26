/*
 Exra Credit 1;
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

#define N 4 // Number of digits to guess

int main()
{   
	// Sets the number
	int num[N], i, j;
	srand(time(NULL));
	for(i = 0; i < N; i++)
	{
		num[i] = rand()%10;
		for(j = 0; j < i; j++)
		{
			while(num[i] == num[j])
			{
				num[i] = rand()%10;
			}
		}
		// Debugging:
		//printf("%d", num[i]);
	}
	int win = 0, tries = 0;
	
	do
	{
		// Guesses the number
		char guess[N + 1];
		printf("Enter your guess: ");
		tries++;
		gets(guess);
	
		// Compares the numbers
		int bulls = 0, cows = 0;
		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				// Uncomment the following for debugging
				//printf("num[j]: %d, num[i]: %d, guess[j]: %d, guess[i]: %d\n", num[j], num[i], guess[j], guess[i]);
				if(num[i] == (int)guess[i] - 48) // 48 = ASCII '0'
				{
					bulls++;
				}
				else if (num[i] == (int)guess[j] - 48)
				{
					cows++;
				}
			}
		}
		bulls /= N;
		
		// Did they win?
		printf("Cows: %d\nBulls: %d\n", cows, bulls);
		if(bulls == N)
		win = 1;
	}while(!win);
	
	// Print stuff
	if(tries > 1)
	{
		printf("You Win!!\nIt took you %d tries!\n", tries);
	}
	else
	{
		printf("Holy Crap!!\nIt took you only %d try!\n", tries);
	}
	
    system("pause");
    return 0;
}
