/*
 Midterm 2;
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
	int n[12], i, j;
	
	for( j = 0; j <= 10; j++){
		printf("6011");
	for( i = 0; i < 12; i++)
	{
		if(i == 0 || i == 4 || i == 8)
		printf("-");
		n[i] = rand()%10;
		printf("%d", n[i]);
		
	}printf("\n");}
	// Sorry about the mess, I heard I need to hurry
    system("pause");
    return 0;
}
