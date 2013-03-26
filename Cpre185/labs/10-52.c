#include <stdio.h>
#include <stdlib.h>

void printChar(char c, int num)
{
     int i;
     for(i = 0; i < num; i++)
     {
           printf("%c", c);
     }
}

int main()
{
    int i, a;
    scanf("%d", &a);
    int stars = 1;
    for(i = 1; i <= a/2; i++)
    {
          printChar(' ', (a - i) / 2);
          printChar('*', stars);
          printf("\n");
          stars += 2;
    }
    printChar('*', stars);
    printf("\n");
    stars -= 2;
    for(i = a / 2; i > 0; i--)
    {
          printChar(' ', (a - i) / 2);
          printChar('*', stars);
          printf("\n");
          stars -= 2;
    }
    system("pause");
    return 0;
}
