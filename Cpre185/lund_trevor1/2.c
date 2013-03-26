#include <stdio.h>
#include <math.h>

int main()
{   
    double L, W, H, dW, dH, gal, paint, area;
    int doors;
    printf("Enter the length of the room: ");
    scanf("%lf", &L);
    printf("Enter the width of the room: ");
    scanf("%lf", &W);
    printf("Enter the height of the room: ");
    scanf("%lf", &H);
    printf("How many doors does the room have? ");
    scanf("%d", &doors);
    printf("What is the height of the door(s)? ");
    scanf("%lf", &dH);
    printf("What is the width of the door(s)? ");
    scanf("%lf", &dW);
    
    area = (2*(L*H) + 2*(L*W)) - ((dH*dW) * doors) + (L*W);
    
    paint = area/20;
    gal = paint/5;
    printf("You must paint %.3f square feet of wall space.\n", area);
    printf("That will require %.3f gallons of paint.\n", paint);
    printf("You will need to buy %.3f 5 gallon buckets of paint.\n", gal);
    system("pause");
    return 0;
}
