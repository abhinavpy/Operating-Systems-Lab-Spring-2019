#include<bits/stdc++.h>
using namespace std;

int mutex=1, full=0, empty=3, x=0;

int wait(int s) {
	return --s;
}

int signalf(int s) {
	return ++s;
}

void producer() {
	mutex = wait(mutex);
	full = signalf(full);
	empty = wait(empty);
	x++;
	printf("producer produces the item %d\n", x);
	mutex = signalf(mutex);
}

void consumer() {
	mutex = wait(mutex);
	full = wait(full);
	empty = signalf(empty);
	printf("Consumer consumes item %d\n", x);
	x--;
	mutex = signalf(mutex);
}

int main()
{
	int n;

	printf("\n1.producer\n2.consumer\n3.Exit\n");

	while(1) {
		printf("Enter your choice\n");
		scanf("%d",&n);

		switch(n) {
			case 1: 
			{
				if(mutex == 1 && empty != 0)
					producer();
				else
					printf("Buffer is full\n");
				break;
			}
			case 2:
			{
				if(mutex == 1 && full != 0)
				{
					consumer();
				}
				else
				{
					printf("Buffer is empty!\n");
				}
				break;
			}
			case 3:
			{
				exit(0);
				break;
			}
		}
	}

	return 0;
}