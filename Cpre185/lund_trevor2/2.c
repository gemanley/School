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
{   char s = ' ', l = '|', u = '_';
	char a[6][3][3] ={{{' ', '_', ' '},
					{'|', '_', '|'},
					{'|', ' ', '|'}},
					{{' ', ' ', ' '},
					 {'|', '_', ' '},
					 {'|', '_', '|'}},
					{{' ', u, s},
					 {l, s, s},
					 {l, u, s}},
					{{s,s,s},
					 {s, u, l},
					 {l, u, l}},
					{{s, u, s},
					 {l, u, s},
					 {l, u, s}},
					{{s, u, s},
					 {l, u, s},
					 {l, s, s}}};
	int i, j, r, n;
	srand(time(NULL));
	r = rand()%6;
	n = rand()%6;
	for(i = 0; i < 3; i++)
	{
		
		for(j = 0; j < 3; j++)
		{
			printf("%c", a[r][i][j]);
		}
		printf("\t");
		
		for(j = 0; j < 3; j++)
		{
			printf("%c", a[n][i][j]);
		}
		printf("\n");
	}
		
    system("pause");
    return 0;
}
