/*
 HW 6; PP11
 October 17th, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <math.h>
void getFinal(double ar1[], double ar2[], int len1, int len2)
{
	double final[len1 + len2];
	int j, i;
	
	for (i = 0; i < len1; i++) {
		final[i] = ar1[i];
		final[i + len1] = ar2[i];
	}
	
	int minIndex; 
	for(i = 0; i < (len1 + len2) -1; i++) 
	{ 
		// find the minimum element in the unsorted part of the array 
		minIndex = i; 
		for(j = i + 1; j < (len1 + len2); j++) 
			if(final[j] < final[minIndex]) 
				minIndex = j; 

		// Swap a[i] with the smallest element 
		int temp = final[i]; 
		final[i] = final[minIndex]; 
		final[minIndex] = temp; 
	} 
	for (i = 0; i < len1 + len2; i++)
	{
		printf("%.f\n", final[i]);
	}
}
int main()
{   
	int len1, len2, i;
	printf("How long is the first array? ");
	scanf("%d", &len1);
	printf("How long is the second array? ");
	scanf("%d", &len2);
    double ar1[len1], ar2[len2], final[len1 + len2];
	printf("Enter the values for the first array: ");
	for(i = 0; i < len1; i++)
	{
		scanf("%lf", &ar1[i]);
	}
	printf("Enter the values for the second array: ");
	for(i = 0; i < len2; i++)
	{
		scanf("%lf", &ar2[i]);
	}
	getFinal(ar1, ar2, len1, len2);
    system("pause");
    return 0;
}

