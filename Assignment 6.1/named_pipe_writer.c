/*This program writes first then reads*/
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd ;

	char *fpath = "/tmp/fifo";/*File path*/
	mkfifo(fpath,0666);/*Made the fifo file*/
	/*Now the operation is done */
	char ar1[80],ar2[80];
	while(1){
/*First we have to write */
		/*Format of open : int open(const char *pathname, int flags); 
int open(const char *pathname, int flags, mode_t mode);  eg:- O_WRONLY is flag*/
		fd = open(fpath,O_WRONLY);/*The Fifo file is opened*/
		/*Format of fgets : fgets(string,size,stdin); */
		fgets(ar2,80,stdin);/*First store the data in array */
		/*Format of write : 
ssize_t write(int fd, const void *buf, size_t count); 
*/		
		write(fd,ar2,strlen(ar2)+1);
		/*Now close the file*/
		/*close format : close(int fd); */
		close(fd);
		/*Now read from the other part*/ 
		fd = open(fpath,O_RDONLY);
		/*Read format : 
ssize_t read(int fd, void *buf, size_t count); */
		read(fd,ar1,sizeof(ar1));
		printf(" User 2: %s \n",ar1);
		close(fd);
	}
	return 0;
}