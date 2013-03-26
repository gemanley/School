#include <stdlib.h>
#include <stdio.h>

int main()
{
    int i, m, k, n;
    scanf("%d", &n);
    for  (i=1;i<=n;i++)
    {
         if(m==0)
         {
                  for(k = 1; k<=n-i; k++)
                  {
                        printf("  ");
                        for(k=1;k<2*i;k++)
                        {
                                          printf("%s","*");
                        }
                  }
         }
    }
system("pause");
return 0;
}
