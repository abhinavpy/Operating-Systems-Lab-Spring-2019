#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>

int main()
{
	int file = 0;
	if((file = open("test.txt", O_RDONLY | O_RDWR)) < -1)
		return 1;

	char buffer[19];
	if(read(file, buffer, 19) != 19) return 1;
	printf("%s\n", buffer);

	if(lseek(file, 10, SEEK_SET) < 0) return 1;
	
	if(read(file, buffer, 19) != 19) return 1;
	printf("%s\n", buffer);

	return 0;
}
