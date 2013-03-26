#include "SoundIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


/**********************************************
 * *************WAV****************************
 * *******************************************/
 
struct wavfile
{
    char        id[4];          // should always contain "RIFF"
    int     totallength;    // total file length minus 8
    char        wavefmt[8];     // should be "WAVEfmt "
    int     format;         // 16 for PCM format
    short     pcm;            // 1 for PCM format
    short     channels;       // channels
    int     frequency;      // sampling frequency
    int     bytes_per_second;
    short     bytes_by_capture;
    short     bits_per_sample;
    char        data[4];        // should always contain "data"
    int     bytes_in_data;
};

char * read_wav(char *filename) {
    FILE *wav = fopen(filename,"rb");
    struct wavfile header;

    if ( wav == NULL ) {
        return "Can't open input file\n";
    }


    // read header
    if ( fread(&header,sizeof(header),1,wav) < 1 )
    {
        return "Can't read file header\n";
    }
    if (    header.id[0] != 'R'
         || header.id[1] != 'I' 
         || header.id[2] != 'F' 
         || header.id[3] != 'F' ) { 
        return "ERROR: Not wav format\n"; 
    }

	

/*    // read data
    long sum=0;
    short value=0;
    while( fread(&value,sizeof(value),1,wav) ) {
        // fprintf(stderr,"%d\n", value);
        if (value<0) { value=-value; }
        sum += value;
    }
    printf("%ld\n",sum);
    return 1;*/
}

int makeWAVFile(char *filename, int sample_rate, int samples, int channels, int bitres, int frequency)
{
	double samplesPerCycle = sample_rate / frequency;
	FILE * file;
	
	if(channels != 1 && channels != 2)
	{
		printf("Channels must be either 1 or 2.  Value passed in was %d\n", channels);
	}
	if(bitres != 8 && bitres != 16 && bitres != 32)
	{
		printf("Bitres must be 8, 16, or 32.  Value passed in was %d\n", bitres);
	}
	int i;
	float amplitude = 102;
	float phase = 0;
	/*float freq_radians_per_sample = frequency * 2 * M_PI / sample_rate;*/
	printf("Writing header\n");
	write_wav_header(filename, sample_rate, samples, channels, bitres);
	if(!strcmp(filename, "stdout"))
	{
		file = fopen(filename, "a");
	}
    printf("Writing file\n");
	for(i = 0; i < samples*channels; i++)
	{
		//phase += freq_radians_per_sample;
		phase = i / samplesPerCycle * 2 * M_PI;
		if(!strcmp(filename, "stdout"))
		{
			fprintf(file, "%c", (int)(amplitude * sin(phase)));
		}
		else
		{
			fprintf(stdout, "%c", (int)(amplitude * sin(phase)));
		}
	}
	if(!strcmp(filename, "stdout"))
	{
		fclose(file);
	}
	return 1;
}

/* Creates a WAV file from an array of ints.
 * Output is monophonic, signed 16-bit samples
 * copyright
 * Fri Jun 18 16:36:23 PDT 2010 Kevin Karplus
 * Creative Commons license Attribution-NonCommercial
 *	http://creativecommons.org/licenses/by-nc/3.0/
 */
void write_little_endian(unsigned int word, int num_bytes, FILE *wav_file, int is_stdout)
{
    printf("In little Endian\n");
    unsigned buf;
    while(num_bytes>0)
    {   buf = word & 0xff;
    	if(!is_stdout)
    	{
    		fwrite(&buf, 1,1, wav_file);
    	}
    	else
    	{
    		fwrite(&buf, 1,1, stdout);
    	}
        num_bytes--;
	word >>= 8;
    }
}

void write_wav_header(char * filename, unsigned int s_rate, unsigned long num_samples, unsigned int num_channels, unsigned int bits_per_sample)
{
    FILE* wav_file;
    unsigned int sample_rate;
    unsigned int byte_rate;
    /*unsigned long i;	 counter for samples */

    if (s_rate<=0) sample_rate = 44100;
    else sample_rate = (unsigned int) s_rate;
    int is_stdout = !strcmp(filename, "stdout");

    byte_rate = sample_rate*num_channels*bits_per_sample;

	if(!is_stdout)
	{
    	wav_file = fopen(filename, "w");
    	assert(wav_file);	/* make sure it opened */
	}

    /* write RIFF header */
    if(is_stdout)
    {
    	fwrite("RIFF", 1, 4, stdout);
    }
    else
    {
    	fwrite("RIFF", 1, 4, wav_file);
    }
    write_little_endian(bits_per_sample* num_samples*num_channels - 8, 4, wav_file, is_stdout);
    if(is_stdout)
    {
    	fwrite("WAVE", 1, 4, stdout);
    }
    else
    {
    	fwrite("WAVE", 1, 4, wav_file);
    }

    /* write fmt  subchunk */
    if(is_stdout)
    {
    	fwrite("WAVE", 1, 4, stdout);
    }
    else
    {
    	fwrite("fmt ", 1, 4, wav_file);
    }
    write_little_endian(16, 4, wav_file, is_stdout);	/* SubChunk1Size is 16 */
    write_little_endian(1, 2, wav_file, is_stdout);	/* PCM is format 1 */
    write_little_endian(num_channels, 2, wav_file, is_stdout);
    write_little_endian(sample_rate, 4, wav_file, is_stdout);
    write_little_endian(byte_rate, 4, wav_file, is_stdout);
    write_little_endian(num_channels*bits_per_sample, 2, wav_file, is_stdout);  /* block align */
    write_little_endian(bits_per_sample, 2, wav_file, is_stdout);  /* bits/sample */

    /* write data subchunk */
    if(is_stdout)
    {
    	fwrite("WAVE", 1, 4, stdout);
    }
    else
    {
    	fwrite("data", 1, 4, wav_file);
    }
    write_little_endian(bits_per_sample* num_samples*num_channels, 4, wav_file, is_stdout);
    /* Used for when data was passed in */
/*    for (i=0; i< num_samples; i++)
    { 	write_little_endian((unsigned int)(data[i]),bits_per_sample, wav_file);
    }*/
	
	if(!is_stdout)
	{
    	fclose(wav_file);
	}
}

/*************************************************
*****CS229*********
**************************************************/

int makeCS229File(char *filename, int sample_rate, int samples, int channels, int bitres, int frequency)
{
	double samplesPerCycle = sample_rate / frequency;
	
	if(channels != 1 && channels != 2)
	{
		printf("Channels must be either 1 or 2.  Value passed in was %d\n", channels);
	}
	if(bitres != 8 && bitres != 16 && bitres != 32)
	{
		printf("Bitres must be 8, 16, or 32.  Value passed in was %d\n", bitres);
	}
	/*FILE *file = fopen(filename, "w");*/
	fprintf(stdout, "%s", "CS229\n");
	fprintf(stdout, "SAMPLE_RATE %d\n", sample_rate);
	fprintf(stdout, "SAMPLES %d\n", samples);
	if(channels == 1)
	{
		fprintf(stdout, "CHANNELS MONO\n");
	}
	else if(channels == 2)
	{
		fprintf(stdout, "CHANNELS STEREO");
	}
	fprintf(stdout, "BITRES %d\n", bitres);
	fprintf(stdout, "STARTDATA\n");
		
	int i;
	for(i = 0; i < samples * channels; i++)
	{
		short amplitude = 102;
		double value = sin(i / samplesPerCycle * 2 * M_PI) * amplitude;
		fprintf(stdout, "%f", value);
	}
	/*fclose(file);*/
	return 1;
}