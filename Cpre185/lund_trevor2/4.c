/*
 Midterm 2;
 October 26th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>

void convert(char letter)
{
	int num = letter;
	int x, y;
 	x = y = 0;

 	for(y = 7; y >= 0; y--) {
  	x = num / (1 << y);
  	num = num - x * (1 << y);
  	printf("%d", x);
	}
}

int main()
{   
	//char text[] = "Halloween";
	char text[] = "Secret Message";
	
	int i = 0, j;
	do
	{
		printf("%c", text[i]);
		i++;
		
	}while(text[i] != '\0');
	printf("\n");
	for(j = 0; j < i; j++)
	{
		convert(text[j]);
		printf("\n");
	}
		
    system("pause");
    return 0;
}
