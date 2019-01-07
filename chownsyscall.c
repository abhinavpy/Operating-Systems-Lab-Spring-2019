#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<errno.h>

int main()
{
	int access = chown("file.txt", -1, -1);
	if(access < 0)\
	{
		perror("Result");
	}
	else
		printf("file.txt 's permissions have not been changed\n"); 	
	return 0;
}
