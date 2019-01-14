#include<bits/stdc++.h>
using namespace std;

void findwaitingTime(int process[], int at[], int bt[], int n, int wt[]) {
	wt[0] = 0;
	for(int i=1;i<n;++i) {
		wt[i] = wt[i-1] + bt[i-1] - at[i];
	}
}


void findturnaroundTime(int process[], int at[], int bt[], int n, int wt[], int tat[]) {
	for(int i=0;i<n;++i) {
		tat[i] = wt[i] + bt[i];
	}
}

void findavgTime(int process[], int at[], int bt[], int n) {
	int wt[n], tat[n], total_wt=0, total_tat = 0;
	findwaitingTime(process, at, bt, n, wt);
	findturnaroundTime(process, at, bt, n, wt, tat);

	cout << "Processes  " << "Arrival Time  " << " Burst time  "
         << " Waiting time  " << " Turn around time\n"; 
  
    for (int  i=0; i<n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << "   " << i+1 << "\t\t" << at[i] << "\t\t" << bt[i] <<"\t    "
            << wt[i] <<"\t\t  " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = " 
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = " 
         << (float)total_tat / (float)n << endl; 
}


int main()
{
	int n;
	printf("enter the number of processes:\n");
	scanf("%d",&n);
	
	int process[n];		
	printf("Enter the processes arrival time:\n");
	int at[n];
	for(int i=0;i<n;++i) {
		scanf("%d",&at[i]);
	}

	printf("Enter the processes burst time:\n");
	int bt[n];
	for(int i=0;i<n;++i) {
		scanf("%d",&bt[i]);
	}

	findavgTime(process,at,bt,n);
	return 0;
}
