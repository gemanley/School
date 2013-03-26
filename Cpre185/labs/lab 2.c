#include <stdio.h>
#include <math.h>

int main()
{
    int dec, bin, temp;
    scanf("%d", &dec);
    temp = dec/128;
    dec = dec%128;
    printf("%d", temp);
    temp = dec/64;
    dec = dec%64;
    printf("%d", temp);
    temp = dec/32;
    dec = dec%32;
    printf("%d", temp);
    temp = dec/16;
    dec = dec%16;
    printf("%d", temp);
    temp = dec/8;
    dec = dec%8;
    printf("%d", temp);
    temp = dec/4;
    dec = dec%4;
    printf("%d", temp);
    temp = dec/2;
    dec = dec%2;
    printf("%d", temp);
    temp = dec;
    printf("%d\n", temp);
    system("pause");
}
