#include<bits/stdc++.h>
using namespace std;
struct process
{
	int pid, bt;
};

int n;

bool compare(process a, process b) {
	return a.bt < b.bt;
}

void findWaitingTime(process proc[], int n, int wt[]) 
{ 
    wt[0] = 0; 
   
    for (int i = 1; i < n ; i++ ) 
        wt[i] = proc[i-1].bt + wt[i-1] ; 
} 
  
void findTurnAroundTime(process proc[], int n, 
                        int wt[], int tat[]) 
{ 
    for (int i = 0; i < n ; i++) 
        tat[i] = proc[i].bt + wt[i]; 
} 


void findAvgTime(process proc[], int n) {
	int wt[n], tat[n], ct[n], total_wt = 0, total_tat = 0; 
  
    findWaitingTime(proc, n, wt); 
  
    findTurnAroundTime(proc, n, wt, tat); 
  
    cout << "\nProcesses "<< " Burst time "
         << " Waiting time " << " Turn around time\n"; 
  
  
    for (int i = 0; i < n; i++) 
    { 
        total_wt = total_wt + wt[i]; 
        total_tat = total_tat + tat[i]; 
        cout << " " << proc[i].pid << "\t\t"
             << proc[i].bt << "\t " << wt[i] 
             << "\t\t " << tat[i] <<endl; 
    } 
  
    cout << "Average waiting time = "
         << (float)total_wt / (float)n; 
    cout << "\nAverage turn around time = "
         << (float)total_tat / (float)n; 
}

int main() {
	
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	struct process p[n];
	printf("Enter the process details as follows\nPID BT\n");
	for(int i=0;i<n;++i) {
		scanf("%d",&p[i].pid);
		scanf("%d",&p[i].bt);
	}

	sort(p,p+n,compare);

	printf("Order in which process gets executed\n");
	for(int i=0;i<n;++i) {
		cout << p[i].pid << " ";
	}

	findAvgTime(p,n);
	
	return 0;
}
