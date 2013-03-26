#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SoundIO.h"

#define SAMPLE_RATE 8000
#define CHANNELS 1
#define BITRES 8

int makeCS229File(char *filename, int sample_rate, int samples, int channels, int bitres, int frequency);
int makeWAVFile(char *filename, int sample_rate, int samples, int channels, int bitres, int frequency);

int main(int argc, char *argv[])
{
	int frequency = 0;
	char *format = "";
	double duration = 0;
	if(argc != 4)
	{
		printf("4 arguments required for %s\nOnly %d arguments were provided\n", argv[0], argc);
		return 0;
	}
	else
	{
		frequency = atoi(argv[1]);
		format = argv[2];
		duration = atof(argv[3]);
	}
	
	if(!strcmp(format, "CS229"))
	{
		makeCS229File("stdout", SAMPLE_RATE, SAMPLE_RATE*duration, CHANNELS, BITRES, frequency);
	}
	else if(!strcmp(format, "WAV"))
	{
		makeWAVFile("stdout", SAMPLE_RATE, SAMPLE_RATE*duration, CHANNELS, BITRES, frequency);
	}
	
	return 0;
}