/*
 HW 10; PP4;
 November 21st, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void removestuff(char word[])
{
	char ret[1023];
	int j = 0, i = 0;
	if(ispunct(word[0]))
		i++;
	while(word[i] != '\0')
	{
		//printf("word[i]: %c, i: %d\n", word[i], i);
		if(!ispunct(word[i]) || (ispunct(word[i]) && isalpha(word[i - 1]) && isalpha(word[i + 1])))
		{
			ret[j++] = word[i];
		}
		i++;
	}
	ret[j] = '\0';
	strcpy(word, ret);
}

int countletters(char word[])
{
	int i = 0, count = 0;
	while(word[i] != '\0')
	{
		if(isalpha(word[i]))
			count++;
		i++;
	}
	return count;
}

int main()
{   
	FILE *in;
	FILE *out;
	in = fopen("phrase.txt", "r");
	out = fopen("words.txt", "w");
	
	int i = 0, num;
	char word[1023];
	
	while(fscanf(in, "%s", &word) != EOF)
	{
		removestuff(word);
		num = countletters(word);
		fprintf(out, "%s %d\n", word, num);
		i++;
	}
	printf("There are %d words in the file.\n\n", i);
	
	fclose(out);
	fclose(in);
    system("pause");
    return 0;
}
