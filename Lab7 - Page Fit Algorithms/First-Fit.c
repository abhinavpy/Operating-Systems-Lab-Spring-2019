#include<stdio.h>
#include<stdlib.h>

void firstFit(int proc[], int bloc[], int procSize, int blockSize) {
	int allocation[procSize];

	for(int i=0; i< blockSize; ++i) {
		allocation[i] = -1;
	}



	for(int i=0; i< procSize; ++i) {
		for(int j=0; j < blockSize; ++j) {
			if(bloc[j] >= proc[i]) {
				allocation[i] = j;
				bloc[j] -= proc[i];
				break;
			}
		}		
	}

	printf("Proc no.\tProc Size\tBlock no\n");
	for(int i=0; i< procSize;++i) {
		printf("\t%d\t%d\t", i+1, proc[i]);
		if(allocation[i] != -1) {
			printf("%d\n", allocation[i] + 1);
		}
		else {
			printf("Not allocated\n");
		}
	}
}


int main() {
	int procSize, blockSize;

	printf("Enter the number of processes: ");
	scanf("%d", &procSize);

	printf("Enter the number of main memory block available: ");
	scanf("%d", &blockSize);

	int proc[procSize+1], memoryBlock[blockSize+1];

	printf("enter the processes size:\n");

	for(int i=0; i<procSize; ++i) {
		scanf("%d", &proc[i]);
	}

	printf("enter the block size: \n");

	for(int i=0; i<blockSize; ++i) {
		scanf("%d", &memoryBlock[i]);
	}

	firstFit(proc, memoryBlock, procSize, blockSize);


	return 0;
}