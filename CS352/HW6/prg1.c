#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <semaphore.h>
pthread_t tids[3];
sem_t mysem;
int count=0;

void *th0(void *x)
{
	printf("Th0 starts.\n");

	/*following is a critical section -- 
		as shared variable count is accessed*/
	sem_wait(&mysem);
	printf("Th 0: Count=%d\n", count);
	count = count + 1;
	sleep(1);
	count = count - 1;
	printf("Th 0: Count is changed to %d\n", count);
	sem_post(&mysem);
}

void *th1(void *x)
{
	printf("Th1 starts.\n");

	/*following is a critical section*/
	sem_wait(&mysem);
	printf("Th 1: Count=%d\n", count);
	count = count + 2;
	sleep(1);
	count = count - 2;
	printf("Th 1: Count is changed to %d\n", count);
	sem_post(&mysem);
}

void *th2(void *x)
{
	printf("Th2 starts.\n");

	/*following is a critical section*/
	sem_wait(&mysem);
	printf("Th 2: Count=%d\n", count);
	count = count - 3;
	sleep(1);
	count = count + 3;
	printf("Th 2: Count is changed to %d\n", count);
	sem_post(&mysem);
}

int main()
{	
	sem_init(&mysem, 0, 1);
	pthread_create(tids,NULL,th0,NULL);
	pthread_create(tids+1,NULL,th1,NULL);
	pthread_create(tids+2,NULL,th2,NULL);
	pthread_join(tids[0], NULL);
	pthread_join(tids[1], NULL);
	pthread_join(tids[2], NULL);
	sem_destroy(&mysem);
}
