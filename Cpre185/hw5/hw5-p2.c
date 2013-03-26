/*
HW 5; 2
October 4th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    int i, n;
    for(n=1; n<=5; n++)
	{
		for(i=1; i<=n; i++ )
	  		printf("%d", i);
	  		
	  	printf("\n");
	}
	for(n=4; n>0; n--)
	{
		for(i=1; i<=n; i++ )
	  		printf("%d", i);
	  		
	  	printf("\n");
	}
    system("pause");
    return 0;
}
