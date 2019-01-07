#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("Linking the file reftextforlink.txt, the new file will be linkedfile.txt\n");
	link("reftextforlink.txt","linkedfile.txt");
	return 0;
}
