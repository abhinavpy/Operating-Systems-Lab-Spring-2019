#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>

pthread_t *phil;

//Declare all semaphores and mutexes that will be required for the program
sem_t mutex, spoon[10];

void* eating


int main()
{
	int i, err;

	// Set the seed of the function to give random numbers every time
	srand(time(NULL));

	// Initialize semaphores
	sem_init(&mutex, 0, 1);

	// Enter the number of Philosophers
	printf("Enter the number of philosophers: ");
	scanf("%d", &phil_count);

	for(int i=0;i<n;++i)
	{
		sem_init(spoon+i, 0, 1);
	}

	for(int i=0;i<n;++i)
	{
		pthread_create(phil+i, NULL, )
	}
	phil_eating = 
	return 0;
}