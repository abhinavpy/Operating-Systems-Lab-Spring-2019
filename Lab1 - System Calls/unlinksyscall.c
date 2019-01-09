#include<unistd.h>
#include<stdio.h>
int main()
{
	printf("First let's link a file. reftextforlink.txt is the file and we link linkedfile.txt to it.\n");
	link("reftextforlink.txt","linkedfile.txt");
	printf("Files are linked and linkedfile.txt is created\n");
	unlink("linkedfile.txt");
	printf("linkedfile.txt is destroyed now, because we have unlinked it.\n");
	return 0;
}
