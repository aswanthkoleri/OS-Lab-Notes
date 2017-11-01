#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/wait.h>/* To use wait() */
#include <sys/shm.h>/* For shared memory  */
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>/* For interprocess communication */
#include <stdio.h>

int main()
{
    int pid1,pid2;
    pid1 = fork();
    if(pid1 == 0)
}