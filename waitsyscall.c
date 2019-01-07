#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t cpid;
	if(fork() == 0)
		exit(0);
	else
		cpid = wait(NULL);
	printf("Parent pid = %d\n", getpid());
	printf("Child pid = %d\n", cpid);

	return 0;
}
