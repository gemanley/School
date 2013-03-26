/*
HW 5; PP10
October 10th, 2010
Programmer: Trevor Lund
Instructor: Alex Stoychev
Class: Cpr E 185 Section J
*/

#include <stdio.h>
#include <math.h>

int main()
{   
    double N = .014, A, S = .0015, depth, R, target = 1000.0, percent, flow;
    double e = 2.0/3.0;
    
    printf("At a depth of 5.0000 feet, the flow is 641.3255 cubic feet per second.\n\n");
    printf("Enter your initial guess for the channel depth when the flow is %.4lf cubic feet per second.", target);
    do
    {
                  printf("Enter guess> ");
                  scanf("%lf", &depth);
                   R = (depth*15.0) / ((2.0*depth) + 15.0);
                   A = depth*15;
                   flow = (1.486 / N) * A * pow(R, e) * pow(S, 0.5);
                   percent = (target - flow) / target * 100;
                   printf("Depth: %.4lf  Flow: %.4lf cfs  Target: %.4lf cfs\nDifference: %.4lf  Error: %.4lf percent\n", depth, flow, target, target - flow, percent);
    }while(percent > .1 || percent < -.1);
    system("pause");
    return 0;
}
