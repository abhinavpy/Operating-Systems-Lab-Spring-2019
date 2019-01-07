#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{
	umask(S_IWGRP | S_IWOTH);
	int fd = open("file.txt", O_CREAT | O_WRONLY, 0777);
	if(fd < 0)
	{
		perror("Result:");
	}
	return 0;
}
