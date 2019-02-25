#include<stdio.h>
#include<stdlib.h>

int main() {
    int nProc, nRes;
    printf("Enter the number of processes:\n");
    scanf("%d", &nProc);
    printf("Enter the number of resources:\n");
    scanf("%d" &nRes);

    int max[nProc][nRes], allocation[nProc][nRes], need[nProc][nRes];

    printf("Enter the maximum resources needed array for each process as a row:\n");
    for(int i=0;i<nProc;++i)
        for(int j=0;j<nRes;++j)
            scanf("%d", &max[i][j]);

    printf("Enter the allocated resources in the similar way:\n");
    for(int i=0;i<nProc;++i)
        for(int j=0;j<nRes;++j)
            scanf("%d", & allocation[i][j]);

    printf("Need matrix is:\n");
    for(int i=0;i<nProc;++i) {
        for(int j=0;j<nRes;++i) {
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
            sum += need[i][j];
        }
        work[i] = sum;
    }

    int finish[nProc];
    for(int i=0;i<nProc;++i)
        finish[i] = 0;

    for(int i=0;i<nProc;++i)
        for(int j=0;j<nRes;++j)
            if(finish[i] == 1 ||  
}
