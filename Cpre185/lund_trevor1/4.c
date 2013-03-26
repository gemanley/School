#include <stdio.h>
#include <math.h>

int main()
{   
    double Q, v, y0, d;
    printf("Enter launch angle Q (in degrees): ");
    scanf("%lf", &Q);
    printf("Enter starting velocity v (in m/s): ");
    scanf("%lf", &v);
    printf("Enter starting elevation y0 (in meters above 0): ");
    scanf("%lf", &y0);
    
    Q = Q / 180 * M_PI;
    
    d = (v*cos(Q))/9.8;
    d *= v*sin(Q) + sqrt(pow((v*sin(Q)), 2) + 2*9.8*y0);
    
    printf("The horizontal travel distance before the impact is %.4f meters.\n", d);
    system("pause");
    return 0;
}
