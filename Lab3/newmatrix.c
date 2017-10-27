#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

int mata[10][10];
int matb[10][10];
int matc[10][10];
int start[10];
int end[10];
int m,n,y,z;
int nothreads;
void *func(void *args){
	long q = (long) args;
	int i = (int) q;
for(int b=start[i];b<end[i] && b<m;b++){
	for(int u=0;u<z;u++){
				int sum=0;
				for(int v=0;v<y;v++){
					sum+=mata[b][v]*matb[v][u];
				}
			matc[b][u]=sum;

	}
}
}

int main(int argc,char *argv[]){

	int i,j;
	pthread_t thread[10];
	int ret[10];
	scanf("%d",&nothreads);
	scanf("%d%d%d%d",&m,&n,&y,&z);
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&mata[i][j]);
		}
	}

	for(i=0;i<y;i++){
		for(j=0;j<z;j++){
			scanf("%d",&matb[i][j]);
		}
	}

	int row=0;
	
	int rem = m%nothreads;
	for(i=0;i<nothreads;i++){

		start[i]=row;
		end[i]=row+(m/nothreads);
		if(rem!=0){
			end[i]++;
			rem--;
		}
		row=end[i];
	}


	for(i=0;i<nothreads;i++){
		ret[i]=pthread_create(&thread[i],NULL,func,(void *)((long)i));
	}

	for(i=0;i<nothreads;i++){
		ret[i]=pthread_join(thread[i],NULL);
	}

	for(i=0;i<m;i++){
		for(j=0;j<z;j++){
			printf("%d ",matc[i][j]);
		}
		printf("\n");
	}

}