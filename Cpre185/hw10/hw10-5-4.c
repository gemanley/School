/*
 HW 10; PP5-4;
 November 30th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void change(char file[])
{
	int i = 0;
	while(file[i] != '\0')
		i++;
	file[i] = '.';
	file[i + 1] = 'l';
	file[i + 2] = 'i';
	file[i + 3] = 's';
	file[i + 4] = '\0';
	//int num = strstr(file, '.');
	//strcpy(num, ".lis\0");
}

int main()
{   
	FILE *in;
	FILE *out;
	char file[1023], line[1024], nfile[1023];
	int i = 1;
	printf("Enter the file: ");
	gets(file);
	in = fopen(file, "r");
	strcpy(nfile, file);
	change(file);
	out = fopen(file, "w");
	
	fprintf(out, "************************** %s **************************\n", nfile);
	
	while(fgets(line, 1024, in) != NULL)
	{
		fprintf(out, "%d %s", i, line);
		i++;
	}
	
	fclose(in);
	fclose(out);
    system("pause");
    return 0;
}
