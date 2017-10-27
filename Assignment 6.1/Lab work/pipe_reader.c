#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd;
	char *fpath = "/tmp/mypipe";
	printf("Creating named pipe: /tmp/mypipe ");
	mkfifo(fpath,0666);
	int flag=1;
	char ar2[80];
	while(flag==1)
	{
		fd=open(fpath,O_RDONLY);
		read(fd,ar2,sizeof(ar2));
		printf("Waiting for input got it : %s\n",ar2);
		printf("%s exit",ar2);
		if(strcmp(ar2,"exit")==0){
		printf("Exiting\n");
		close(fd);
		flag=0;
		}
	}
return 0;
}