/*
 HW 10; PP5;
 November 26th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
	int p1;
	int p2;
	int p3;
	int p4;
	char nick[10];
}  address_t;

address_t scan_address(FILE *in)
{
	address_t dress;
	fscanf(in, "%d.%d.%d.%d", &dress.p1, &dress.p2, &dress.p3, &dress.p4);
	fscanf(in, "%s", &dress.nick);
	return dress;
}

void print_address(address_t IP)
{
	printf("%d.%d.%d.%d   %s\n", IP.p1, IP.p2, IP.p3, IP.p4, IP.nick);
}	

int local_address(address_t IP1, address_t IP2)
{
	return (IP1.p1 == IP2.p1 && IP1.p2 == IP2.p2);
}
int main()
{   
	FILE *in;
	in = fopen("addresses.txt", "r");
	int i = -1, j, num;
	address_t IP[100];
	
	do
	{
		i++;
		IP[i] = scan_address(in);
		//printf("%d:%s\n", i, IP[i].nick);
		//printf("Strcmp[%s, %d]", IP[i].nick, strcmp(IP[i].nick, "none\0"));
	}while(strcmp(IP[i].nick, "none") != 0);
	
	num = i;
	for(i = i - 1; i >= 0; i--)
	{
		for(j = 0; j < i; j++)
		{
			if(local_address(IP[i], IP[j]))
			{
				//printf("%d:%d", i, j);
				printf("Machines %s and %s are on the same local network.\n", IP[i].nick, IP[j].nick);
			}
		}
	}
	printf("\n");
	for(i = 0; i < num; i++)
	{
		print_address(IP[i]);
	}
	printf("\n");
	fclose(in);
    system("pause");
    return 0;
}
