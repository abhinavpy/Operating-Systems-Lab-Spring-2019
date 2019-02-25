#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#include<stdlib.h>

#define BUF_SIZE 2

struct buffer {
    int data;
};

struct buffer buf[BUF_SIZE];

sem_t fill, empty;

int value, i;

void *producer(void *data);
void *consumer(void *data);

int main(void)
{
    int sel, prod_data, cons_data;
    int k;

    if(sem_init(&empty, 0, BUF_SIZE))
    {
        printf("Error: semaphore not initialized\n");
        return -1;
    }

    if(sem_init(&fill, 0, 0))
    {
        printf("Error: semaphore not initialized\n");
        return -1;
    }

    while(1) {
        printf(".........................................................\n");
        printf("Selection\n");
        printf("Producer : 1 | Consumer : 2 | Display : 3 | Exit : 0 || ");
        scanf("%d",&sel);
        printf(".........................................................\n");

        switch (sel)
        {
            case 1:
                sem_getvalue(&empty, &value);
                sem_geta
                break;
        
            default:
                break;
        }

    }
}