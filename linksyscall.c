#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Linking the file reftextforlink.txt, the new file will be linkedfile.txt\n");
	if(link("reftextforlink.txt","linkedfile.txt") < 0)
		printf("Error while linking file. link returned -1.");
	else
		printf("Linking is successful\n");
	return 0;
}
