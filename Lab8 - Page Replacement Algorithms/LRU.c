#include<stdio.h>
#include<stdlib.h>

struct RAM {
    int noOfPageFrames;
    int *arr;
    int *rank;
};

// Works only with 3 Page Frames other wise fails.
int main() 
{
    int n;
    int noOfPageRef;
    int ifPageFound = 0;
    printf("Enter the number of page frames in the ram\n");
    scanf("%d", &n);
    struct RAM* ram = (struct RAM*) malloc(sizeof(struct RAM));

    ram -> noOfPageFrames = n;

    ram -> arr = (int *)malloc(sizeof(int) * n);

    ram -> rank = (int *)malloc(sizeof(int) * n);

    for(int i=0; i < n; ++i) 
    {
        ram -> rank[i] = 0;
        ram -> arr[i] = -1;
    }

    printf("Enter the number of page references to be made: \n");
    
    scanf("%d", &noOfPageRef);

    printf("Enter the first %d references to be added into the ram\n", n);
    for(int i=0; i < ram -> noOfPageFrames; ++i)
    {
        printf("Enter the page:\n");
        int y;
        scanf("%d", &y);
        ram -> arr[i] = y;
        ram -> rank[i] = i + 1;
    }

    printf("Enter the page references: \n");
    for(int i=0; i < noOfPageRef - (ram -> noOfPageFrames); ++i)
    {
        ifPageFound = 0;
        printf("Enter a number: ");
        int x;
        scanf("%d", &x);
        for(int i=0; i < ram -> noOfPageFrames; ++i)
        {
            if(x == ram -> arr[i]) 
            {
                ifPageFound = 1;
                printf("Page %d found in the RAM. HIT!!, ram -> arr[%d] = %d\n", x, i, ram -> arr[i]);
                switch (ram -> rank[i])
                {
                    case 1:
                    {
                        for(int j=0; j < noOfPageRef; j++) 
                        {
                            ram -> rank[j]--;
                        }
                        ram -> rank[i] = 3;
                        break;
                    }

                    case 2:
                    {
                        for(int j=0; j < noOfPageRef; j++) 
                        {
                            if(ram -> rank[j] == 3)
                            {
                                ram -> rank[j] = 2;
                            }
                        }
                        ram -> rank[i] = 3;
                        break;
                    }
                
                    case 3:
                        break;
                }
            }
        }

        int rankInd = 0;

        if(ifPageFound == 0) {
            printf("Page %d not found in the RAM. MISS!!\n", x);
            for(int i=0; i < ram -> noOfPageFrames; ++i) 
            {
                //printf("DEBUG: inside loop 2\n");
                if(ram -> rank[i] == 1)
                {
                    rankInd = i;
                }
            }

            for(int i=0; i < ram -> noOfPageFrames; ++i) 
            {
                //printf("DEBUG: inside loop 2\n");
                if(ram -> rank[i] == 2)
                {
                    ram -> rank[i] == 1;
                }
                if(ram -> rank[i] == 3)
                {
                    ram -> rank[i] = 2;
                }
            }
            printf("Replaced %d with the new page %d\n", ram -> arr[rankInd], x);
            ram -> rank[rankInd] = 3;
            ram -> arr[rankInd] = x;
        }
    }

    return 0;
}