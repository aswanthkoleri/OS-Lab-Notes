#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int sum ;
void *runner(void *var);
int main()
{
	pthread_t t1;
	pthread_attr_t attr;
	printf("enter a no");
	int n;
	scanf("%d",&n);
	pthread_create(&t1,NULL,runner,(void *)(long)n);
	pthread_attr_init(&attr);
	pthread_join(t1,NULL);
	printf("%d\n",sum);
	return 0;
}
void *runner(void *var)
{
	long n = (long)var;
	printf("The thread started");	
	for(int i=1;i<=n;i++)
	{
		sum = sum + i;
	}
	pthread_exit(0);
}