#include <stdio.h>
#include <unistd.h>
int main()
{
int pid;
int x=0;
pid = fork( );
if (pid>0)
{
x++;
pid=0;
wait( );
printf("x1=%d\n", x);
if(fork()){
wait( );
printf("x2=%d\n",x);
x++;
}else{
x++;
printf("x3=%d\n",x);
if (fork()>0)
printf("pid=%d\n", pid);
}
}
else
{
printf("x4=%d\n", x);
}
} 