#include <pthread.h>

int i;

void *th_code(void *x)
{
	pthread_t tid;
	printf("Hi I'm thread %d\n", x);
	i = i - 1;
	int t = (int) x;
	if(i>0){
		printf("Creating thread %d\n", ++t);
		pthread_create(&tid, NULL, th_code, (void *) t);
		pthread_join(tid, NULL);
	}
}

int main()
{
	pthread_t tid;
	i=3;
	int t = 0;
	printf("Creating thread %d\n", ++t);
	pthread_create(&tid, NULL, th_code, (void *) t);
	pthread_join(tid, NULL);
}