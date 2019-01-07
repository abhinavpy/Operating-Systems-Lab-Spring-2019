#include<stdio.h>
#include<unistd.h>
#include<errno.h>

int main()
{
	printf("Lets access file.txt\n");
	int accessn = access("file.txt", R_OK);
	if(accessn > 0)
		printf("Access has been successful.\n");
	else
		perror("Outcome: ");
	return 0;
}
