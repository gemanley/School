#include <stdlib.h>

int num_threads = 0;
struct {
	int id;
	void * func;
	int priority;
} thread;
thread[30] thread_list = new thread[30];

void system_init()
{
	
}

int uthread_create(void func(), int priority)
{
	thread new_thread;
	new_thread->id = num_threads++;
	new_thread->priority = priority;
	new_thread->func = func;
	thread_list[new_thread->id] = new_thread;
}

int uthread_yield(int priority)
{
}

void uthread_exit()
{
}