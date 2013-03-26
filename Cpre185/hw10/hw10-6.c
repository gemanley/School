/*
 HW 10; PP6;
 December 1st, 2010
 Programmer: Trevor Lund
 Instructor: Alex Stoychev
 Class: Cpr E 185 Section J
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

/*void format(double num)
{
	char converted1[40], temp;
	int i = 0, comma, dig;
	
	sprintf(converted1, "%.2f", num);
	while(converted1[i] != '.')
		i++;
	
	comma = i / 3;
	dig = i % 3;
	for(i = 0; i < 
		
	for(i = i - 4, i > 0; i = i - 4)
	{
		for(j = 
		temp = converted[i];
		converted[i] = ',';
*/
int main()
{   
	double loan, month, tot;
	float lint, hint, i;
	int j;
	printf("Enter the loan amount: ");
	scanf("%lf", &loan);
	printf("Enter the minimum interest rate (whole num only): ");
	scanf("%f", &lint);
	printf("Enter the max interest rate (whole num only): ");
	scanf("%f", &hint);
	
	FILE *out;
	out = fopen("loan.txt", "w");
	
	//format(loan); Realized it's stupid
	fprintf(out, "\t\tLoan Amount: $%.2f\n\n", loan);
	fprintf(out, "Interest   Duration   Monthly       Total\n");
	fprintf(out, "  Rate     (years)    Payment       Payment\n\n");
	
	for(i = lint; i < hint; i = i + .25)
	{
		for(j = 20; j <= 30; j = j + 5)
		{
			month = (((i/100) / 12)*loan) / (1 - pow((1 + (i/100) / 12), -(j*12)));
			tot = month * (j*12);
			fprintf(out, "  %.2f%%     %d       $%.2f     $%.2f\n", i, j, month, tot);
		}
	}
	
	fclose(out);
    system("pause");
    return 0;
}
