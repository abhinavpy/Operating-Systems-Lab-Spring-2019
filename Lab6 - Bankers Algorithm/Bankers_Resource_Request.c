#include<stdio.h>
#include<stdlib.h>

int main() {
    int nProc, nRes;
    printf("Enter the number of processes:\n");
    scanf("%d", &nProc);
    printf("Enter the number of resources:\n");
    scanf("%d", &nRes);

    int max[nProc+1][nRes+1], allocation[nProc+1][nRes+1], need[nProc+1][nRes+1];

    printf("Enter the maximum resources needed array for each process as a row and resources as columns:\n");
    for(int i=0;i<nProc;++i)
        for(int j=0;j<nRes;++j)
            scanf("%d", &max[i][j]);

    printf("Enter the allocated resources in the similar way:\n");
    for(int i=0;i<nProc;++i)
        for(int j=0;j<nRes;++j)
            scanf("%d", &allocation[i][j]);

    printf("Need matrix is:\n");
    for(int i=0;i<nProc;++i) {
        for(int j=0;j<nRes;++j) {
            need[i][j] = max[i][j] - allocation[i][j];
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int total[nRes];
    printf("Enter the total resources present:\n");
    for(int i=0;i<nRes;++i)
        scanf("%d", &total[i]);
    
    int sum = 0;
    int work[nRes];
    for(int i=0;i<nRes;++i) {
        sum = 0;
        for(int j=0;j<nProc;++j) {
            sum += allocation[j][i];
        }
        work[i] = sum;
    }

    printf("The total allocated resources are\n");
    for(int i=0;i<nRes;++i)
    	printf("%d ", work[i]);
    printf("\n");

    for(int i=0;i<nRes;++i)
    	work[i] = total[i] - work[i];

    printf("The total resources available\n");
    for(int i=0;i<nRes;++i)
    	printf("%d ", work[i]);

    printf("\n");

    int finish[nProc];
    for(int i=0;i<nProc;++i)
        finish[i] = 0;

    printf("Enter after how many processes should you insert a new process:\n");
    int num;
    scanf("%d", &num);

    printf("Enter the max of this new process:\n");
    
    for (int i = 0; i < nRes; ++i)
    {
        scanf("%d", &max[nProc+1][i]);
    }

    printf("Enter the allocation of this new process:\n");
    int nAllocation[nRes];
    for (int i = 0; i < nRes; ++i)
    {
        scanf("%d", &allocation[nProc+1][i]);
    }

    printf("The order in which resources are executed are:\n");
    int temp = 0;
    while(temp < nProc+1) {
        if(temp == num) {
            for(int j=0;j<nRes;++j) {
	            if(finish[num] == 1 || need[num][j] > work[j]) {
	            	break;
	            } 
	            else {
                    printf("new_process ->");
	            	++temp;
	            	finish[num] = 1;
	            	printf("P%d -> ", num);
	            	for(int k=0;k<nRes;++k)
	            		work[k] = allocation[num][k] + work[k];
	            }
	        }
        }
	    for(int i=0;i<nProc + 1;++i) {
	        for(int j=0;j<nRes;++j) {
	            if(finish[i] == 1 || need[i][j] > work[j]) {
	            	break;
	            } 
	            else {
	            	++temp;
	            	finish[i] = 1;
	            	printf("P%d -> ", i);
	            	for(int k=0;k<nRes;++k)
	            		work[k] = allocation[i][k] + work[k];
	            }
	        }
	    }
	}
	printf("\n");
}