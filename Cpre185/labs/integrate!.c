#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double myF(double x)
{
       return(x);
}

int main()
{
    double a, b;
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    
    int N; //# of samples
    printf("Define precision: ");
    scanf("%d", &N);
    double deltaX = (b-a)/N;
    
    double I = 0, result = 0;
    int i;
    for(i = 0; i<N; i++)
    {
            result = deltaX * myF(a + i*deltaX);
            I += result;
    }
    
    printf("The integral is: %g\n", I);
    
    system("pause");
    return 0;
}
