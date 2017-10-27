#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
int main(){
	int fd;
	fd = open("newmatrix1",O_RDONLY);
	printf("%d \n",fd);
	if(fd== -1)
	{
		printf("error no is : %d",fd);
		perror("Program");
	}
	if(close(fd)<0)
	{
		perror("Program");

	}
	return 0;
}Hello
