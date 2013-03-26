/*
 HW 7; RQ3
 October 24th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
int isvowel(int i)
{
	if(i == 65 || i == 69 || i == 73 || i == 79 || i == 85)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int main()
{   
	int i;
	for(i = 90; i >= 65; i--)
	{
		if(!isvowel(i))
		{
			printf("%c", i);
		}
	}

    system("pause");
    return 0;
}
