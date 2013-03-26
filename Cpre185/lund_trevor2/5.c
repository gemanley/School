/*
 Midterm 2
 October 26th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{   
	srand(time(NULL));
	int N, i, j, k = 0, h, exists = 0;
	do {
	printf("Enter a number 1 - 20: ");
	scanf("%d", &N);
	}while(N<1 || N>20);
	int s1[N], s2[N], s3[10];
	printf("First set:   ");
	for(i = 0; i < N; i++)
	{
		s1[i] = rand()%10;
		printf("%d, ", s1[i]);
	}
	printf("\nSecond set:  ");
	for(i = 0; i < N; i++)
	{
		s2[i] = rand()%10;
		printf("%d, ", s2[i]);
	}
	
	for(h = 0; h < 10; h++)
	{
		s3[h] = -1;
	}
	printf("\n\nThe following numbers appear in both sets:\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j <= N; j++)
		{
			if(s1[i] == s2[j] && s3[s2[j]] != 1)
			{
			s3[s2[j]] = 1;
			printf("%d, ", s2[j]);
			}
		}
	}
	printf("\n");
    system("pause");
    return 0;
}
