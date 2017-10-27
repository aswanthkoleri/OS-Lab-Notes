#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
int main() {
 int fd, sz;
 fd = open("opencall.c", O_RDWR| O_CREAT | O_APPEND,0644) ;
 if(fd < 0) { perror("opencall.txt"); exit(1); }
 sz = write(fd,"Hello\n",strlen("Hello\n"));
 printf("Return value of write : %d ",sz);
 close(fd);
 return 0;
} 