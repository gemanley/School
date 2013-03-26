/*
 HW 10; PP1;
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

typedef struct
{
	int site_id_num;
	int day_of_month;
	int wind_speed;
	int temperature;
} measured_data_t;

int findVariation(measured_data_t data1[], int i, int num, int vary[])
{
	int current = data1[i].site_id_num, min = data1[i].temperature, max = data1[i].temperature;
	while(data1[i].site_id_num == current)
	{
		if(data1[i].temperature < min)
			min = data1[i].temperature;
		if(data1[i].temperature > max)
			max = data1[i].temperature;
		i++;
	}
	if(vary[1] < (max - min))
	{
		vary[0] = data1[i - 1].site_id_num;
		vary[1] = max - min;
	}
	if(i < num)
	return findVariation(data1, i, num, vary);
	else
	return 1;
	
}

int avgWind(measured_data_t data1[], int i, int num, int avg[])
{
	int current = data1[i].site_id_num, tot = 0, count = 0;
	while(data1[i].site_id_num == current)
	{
		tot += data1[i].wind_speed;
		//printf("i: %d, site: %d, current: %d\n", i, data1[i].site_id_num, current);
		//printf("%d + ", data1[i].wind_speed);
		count++;
		i++;
	}
	//printf("0 = %d\n", tot / count);
	if(avg[1] < (tot / count))
	{
		avg[0] = data1[i - 1].site_id_num;
		avg[1] = tot / count;
	}
	if(i < num)
	return avgWind(data1, i, num, avg);
	else
	return 1;
}

int main()
{   
	FILE *data;
	data = fopen("data.txt", "r");
	measured_data_t data1[310];
	int i = 0, num, vary[2], avg[2];
	vary[1] = -1;
	avg[1] = -1;
	while((fscanf(data, "%d", &data1[i].site_id_num)) != EOF)
	{
		fscanf(data, "%d", &data1[i].day_of_month);
		fscanf(data, "%d", &data1[i].wind_speed);
		fscanf(data, "%d", &data1[i].temperature);
		i++;
	}
	
	num = i;
	findVariation(data1, 0, num, vary);
	printf("Site %d has the greatest temperature variation.\n\n", vary[0]);
	avgWind(data1, 0, num, avg);
	printf("Site %d has the greatest average wind speed.\n\n", avg[0]);
	
	fclose(data);
    system("pause");
    return 0;
}
