#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int file_desc = open("original.txt", O_WRONLY | O_APPEND);
	
	if(file_desc < 0)
		printf("Error opening file\n");

	int copy_desc = dup(file_desc);

	write(copy_desc, "This is text that is being entered into the copy descriptor....\n");
	write(file_desc, "This is text that is beign entered into the file descriptor main....\n");

	return 0;
}
