/*
HW 5; PP6
October 5th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    double input, total;
    int i = 0, cold = 0, hot = 0, ples = 0;
    printf("Enter your temperatures.  Enter 9000 to quit.\n");
    do
    {
          scanf("%lf", &input);
          if (input != 9000)
          {
          i++;
          if (input < 60)
          cold++;
          if (input >= 85)
          hot++;
          if (input >= 60 && input < 85)
          ples++;
          if(i == 1)
               total = input;
          else
          total += input;
          }
    }while (input != 9000);
    
    printf("There were %d hot days (85 degrees or higher), %d pleasant days (between 60 and 85 degrees), and %d cold days (less than 60 degrees).\n", hot, ples, cold);
    printf("The average temperature was %lf.\n", total / i);
          
    system("pause");
    return 0;
}
