#include <stdio.h>
#include <math.h>

int main()
{   
    double x1, x2, y1, y2, L, W, area, S;
    printf("Enter the first point: ");
    scanf("%lf", &x1);
    scanf("%lf", &y1);
    printf("Enter the second point: ");
    scanf("%lf", &x2);
    scanf("%lf", &y2);
    printf("Enter the length of the rectangle: ");
    scanf("%lf", &L);
    printf("Enter the width of the rectangle: ");
    scanf("%lf", &W);
    
    S = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    printf("The outer perimeter of that equilateral triangle is %.2f.\n", S*3);
    area = (.5 * S * (y2 - y1)) - (L * W);
    printf("The area of that triangle (not including the rectangle) is %.2f.\n", area);
    system("pause");
    return 0;
}
