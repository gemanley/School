#include <stdio.h>
#include <math.h>

int main()
{   
    double y, mu, sigma, x;
    printf("Please enter the mean mu : ");
    scanf("%lf", &mu);
    printf("Please enter the standard deviation (sigma): ");
    scanf("%lf", &sigma);
    printf("Please enter a value for x: ");
    scanf("%lf", &x);
    
    y = 1/sqrt(2*M_PI*sigma*sigma);
    y *= exp(-1 * pow((x-mu), 2)/(2*sigma*sigma));
    
    printf("The result is = %f\n", y);
    system("pause");
    return 0;
}
