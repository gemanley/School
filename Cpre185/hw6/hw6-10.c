/*
HW 6; PP10
October 17th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int i, j, votes[5][4], total = 0, tot[4] = {0,0,0,0}, high[2] = {0,0}, win[2];
    float percent[j];
    for(i = 0; i <= 4; i++)
    {
          printf("Enter the results for precinct %d\n", i+1);
          for(j = 0; j <= 3; j++)
          {
                printf("Candidate %c: ", j+65);
                scanf("%d", &votes[i][j]);
          }
    }
    printf("Precinct      | Candidate A | Candidate B | Candidate C | Candidate D");
    for(i = 0; i <= 4; i++)
    {
          printf("\n%13d ", i+1);
          for(j = 0; j <= 3; j++)
          {
                printf("%13d ", votes[i][j]);
                total += votes[i][j];
          }
          for(j = 0; j <= 3; j++)
          {
				tot[j] += votes[i][j];
		}
    }
    
    for(j = 0; j <= 3; j++)
    {
		percent[j] = 100*((float)tot[j]/(float)total);
		printf("\nThe total for Candidate %c is %d.  That is %f%% of the total.\n", j+65, tot[j], percent[j]);
		if(percent[j] > high[0])
		{
			high[0] = percent[j];
			win[0] = j;
		}
	}
	for(j = 0; j <= 3; j++)
    {
		if(percent[j] > high[1] && j != win[0])
		{
			high[1] = percent[j];
			win[1] = j;
		}
	}
	if(high[0] > 50)
	{
		printf("The winner is Candidate %c!", win[0] + 65);
	}
	else
	{
		printf("There will be a runoff between Candidates %c and %c!", win[0] +65, win[1] + 65);
	}
    system("pause");
    return 0;
}
