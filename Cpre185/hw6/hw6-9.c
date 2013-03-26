/*
 HW 6; PP9
 October 18th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>

int main()
{   
	int len;
	printf("How long is the word? ");
	scanf("%d", &len);
	fflush(stdin);
    char guessed[len], guess, word[len];
    int i, guesses = 5, lose, done = 0;
    for(i = 0; i < len; i++)
    {
		guessed[i] = '*';
		printf("Enter letter %d of the word: ", i + 1);
		fflush(stdin);
		scanf("%c", &word[i]);
	}
    do
    {
		for(i = 0; i < len; i++)
		{
			printf("%c", guessed[i]);
		}
		printf("\n%d guesses left.", guesses);
		done = 0;
		for(i = 0; i < len; i++)
		{
			if(guessed[i] == '*')
			done++;	
		}
		if (guesses == 0 || done == 0) {
			break;
		}
		printf("\nGuess a letter: ");
		scanf("\n%c", &guess);
		lose = 1;
		for(i = 0; i < len; i++)
		{
			if(guess == word[i]){
				guessed[i] = guess;
				lose = 0;
			}
			
		}
		if (lose == 1) {
			guesses--;
		}
	} while(done != 0);
	if (guesses != 0) {
		printf("\nYou Win!!");
	}
	else {
		printf("\nYou Lose!!");
	}

    system("pause");
    return 0;
}
