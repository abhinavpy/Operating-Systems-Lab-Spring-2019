#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>

int main(void)
{
	printf("Get a real user id:%d\n", getuid());
	printf("Get the effective user ID: %d\n", geteuid());
	printf("Get the real group ID: %d\n", getgid());
	printf("Get the effective group ID %d\n", getegid());
	printf("Get the real process ID:%d\n", getpid());
	printf("Get the process ID:%d\n", getppid());
	return 0;
}
