#include <stdio.h>
#include <pthread.h>
int a[100][100],b[100][100],r[100][100],d,start[100],end[100],n;
void *runner(void *var)
{
	long pos = (long)var;
	
	for(int i=start[(int)pos];i<end[(int)pos];i++)
	{
		for(int j=0;j<n;j++)
		{
			int sum = 0;
			for(int k=0;k<n;k++)
			{
				sum = sum+a[i][k]*b[k][j];
			}
			r[i][j] = sum;
		}
	}	
		pthread_exit(0);
}

int main()
{

	printf("Enter the matrix dimension \n");
	scanf("%d",&n);
	pthread_t t[10];
	int thr;
	printf("enter the no of threads");
	scanf("%d",&thr);
	int rem = n%thr;
	int row = 0;
	for(int i=0;i<thr;i++)
	{
		start[i] = row;
		row = row + (n/thr);
		end[i] = row;
		if(rem != 0)
		{
			end[i]++;
			rem-- ;
		}
		row++;
	}
	printf("Enter the matrix A : \n");
	for(int i =0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&a[i][j]);
		printf("Enter the matrix B : \n");
	for(int i =0;i<n;i++)
		for(int j = 0;j<n;j++)
			scanf("%d",&b[i][j]);
	for(int id=0;id<thr;id++)
	{
	pthread_create(&t[id],NULL,runner,(void *)(long)id);/*Creates a new thread*/
	}
	
	pthread_join(t[thr-1],NULL);/* pthread_join blocks the calling thread until the thread with identifier equal to the first argument terminates.*/
	printf("The product of the matrix is : \n");
	for(int i=0 ;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d ",r[i][j]);
		}
		printf("\n");
	}
return 0;
}