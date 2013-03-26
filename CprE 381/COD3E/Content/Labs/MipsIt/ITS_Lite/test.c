#include <stdio.h>
#include "its.h"

/* Uncomment next line to run on the simulator  (shorter delay)  */
#define SIM

unsigned int stack1[0x400]; /* Stack for thread 1 */
unsigned int stack2[0x400]; /* Stack for thread 2 */

void Sleep( int n )
{
	int i;

#ifdef SIM
	while (n--);
#else
	while (n--)
		for (i=0;i<0xffff;i++);
#endif
}

void Thread( char *str )
{
	while(1)
	{
		ITS_enter_critical();
		printf("<%s>\n",str);
		ITS_leave_critical();
	
		/* Let the next thread run */
		ITS_yield();
	}
}

main()
{
	int tid1, tid2;
	printf("Scheduler...\n");
	ITS_init();
	tid1 = ITS_create_thread((void *)Thread, "hello, world", &(stack1[0x3ff]));
	tid2 = ITS_create_thread((void *)Thread, "goodbye, cruel world", &(stack2[0x3ff]));

	while (1)
	{
		/* This is thread 0: */

		ITS_enter_critical();
		printf("A");
		ITS_leave_critical();
		Sleep(10);
	}
}