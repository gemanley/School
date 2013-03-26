#include <stdio.h>
#include <math.h>

int main()
{   
    double amount, tax;
    printf("Enter amount: ");
    scanf("%lf", &amount);
    tax = amount * .07;
    printf("\nAmount  $%5.2f", amount);
    printf("\nTax     $%5.2f", tax);
    printf("\nTip     ______\n______________");
    printf("\nTOTAL   ______\n\n\n");
    printf("15%% tip = $%5.2f\n", amount*.15);
    printf("20%% tip = $%5.2f\n", amount*.20);
    printf("25%% tip = $%5.2f\n", amount*.25);
    system("pause");
    return 0;
}
