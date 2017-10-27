/*This program reads first then writes*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd1;
	char *fpath = "/tmp/fifo";
	mkfifo(fpath,0666);
	char str1[80],str2[80];
	while(1){

		/*Reading */
		fd1 = open(fpath,O_RDONLY);
		read(fd1,str1,80);
		printf("User 1 : %s \n",str1);
		close(fd1);
		/*Writing*/
		fd1 =open(fpath,O_WRONLY);
		fgets(str2,80,stdin);
		write(fd1,str2,strlen(str2)+1);
		close(fd1);
	}
	return 0;
}