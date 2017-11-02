#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd;
	char *fpath = "/tmp/mypipe";
	printf("Opening named pipe: /tmp/mypipe \n");
	mkfifo(fpath,0666);
	char ar1[80];
	int flag = 1;
	while(flag==1){
		/*Writing*/
		fd = open(fpath,O_WRONLY);
		printf("Enter Input : ");
		gets(ar1);
		write(fd,ar1,strlen(ar1)+1);
		printf("Writing buffer to pipe.....done\n");
		if(strcmp(ar1,"exit")==0){
		printf("Exiting\n");
		close(fd);
		flag=0;
	}
}
	return 0;
}

