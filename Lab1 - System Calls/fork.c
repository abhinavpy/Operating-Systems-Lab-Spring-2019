#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void forkexample()
{
	if(fork() == 0)
		printf("Hello! from Child!\n");
	else
		printf("Hello! from parent\n");
}

int main()
{
	forkexample();
	return 0;
}
