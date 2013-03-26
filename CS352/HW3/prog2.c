#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main( )
{
	pid_t pid, pid1;
	int value;
	pid = fork( );
	value=0;
	if (pid < 0)
	{
		printf("Fork Failed\n" );
		return(1);
	}
	else if (pid == 0)
	{
		value+=1;
		pid1 = getpid( );
		printf("chid: pid = %d\n", pid); /* A */
		printf("child: pid = %d\n", pid1); /* B */
		printf("child: value=%d\n", value); /* C */
	}
	else
	{
		value+=2;
		pid1 = getpid( );
		printf("parent: pid = %d\n", pid); /* D */
		printf("parent: pid = %d\n", pid1); /* E */
		wait(NULL);
		printf("parent: value=%d\n", value); /* F */
	}
	return 0;
}