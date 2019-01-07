#include <stdio.h> 
	#include <signal.h>
	#include <unistd.h>

	int ctrl_c_count = 0;
	void (* old_handler)(int); 
	void ctrl_c(int);

	main()
	{
		int c;

		old_handler = signal(SIGINT, ctrl_c);
	
		while ((c = getchar())!='\n'); 
			printf("ctrl-c count = %d\n", ctrl_c_count);

		(void) signal(SIGINT, old_handler);

		for (;;);
	}



	void ctrl_c(int signum) 
	{
		(void) signal(SIGINT, ctrl_c); 
		++ctrl_c_count;
	}
