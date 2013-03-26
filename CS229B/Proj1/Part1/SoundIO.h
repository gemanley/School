#ifndef SOUNDIO_H_
#define SOUNDIO_H_

#include <stdio.h>

char * read_wav(char *filename);
void write_wav_header(char * filename, unsigned int s_rate, unsigned long num_samples, unsigned int num_channels, unsigned int bits_per_sample);
void write_little_endian(unsigned int word, int num_bytes, FILE *wav_file, int is_stdout);
int makeWAVFile(char *filename, int sample_rate, int samples, int channels, int bitres, int frequency);
char * read_wav(char *filename);
int makeCS229File(char *filename, int sample_rate, int samples, int channels, int bitres, int frequency);

#endif /*SOUNDIO_H_*/
