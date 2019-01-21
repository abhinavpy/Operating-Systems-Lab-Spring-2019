#include<bits/stdc++.h>
using namespace std;

struct process
{
	int pid,at,bt,wt,tat;
	int rt,compt;
	bool visited;
};

bool sortByAT(struct process A, struct process B)
{
	if(A.at < B.at)
		return true;
	else
		return false;
}

void roundRobinScheduling(struct process P[], int n, int t_quantum)
{
	sort(P,P+n,sortByAT);
	/*for(int i=0;i<n;++i)
	{
		cout << P[i].pid << "\t" << P[i].at << "\t" << P[i].bt << "\n";
	}*/
	int current_time = 0;

	queue <process> Q;
	Q.push(P[0]);
	P[0].visited = true;

	while(!Q.empty())
	{
		struct process temp = Q.front();
		Q.pop();

		if(temp.rt < t_quantum)
		{
			current_time += temp.rt;
			temp.rt -= temp.rt;
		}

		else if(temp.rt >= t_quantum)
		{
			current_time += t_quantum;
			temp.rt -= t_quantum;
		}

		for(int i=0;i<n;++i)
		{
			if(P[i].at <= current_time && P[i].visited == false)
			{
				Q.push(P[i]);
				P[i].visited = true;
			}
		}

		if(temp.rt > 0)
			Q.push(temp);

		else if(temp.rt == 0)
		{
			int id = temp.pid;
			P[id-1].compt = current_time;
			P[id-1].tat = current_time - P[id-1].at;
			P[id-1].wt = P[id-1].tat - P[id-1].bt;
		}
	}

	cout << "PID" << "\t" << "AT" << "\t" << "BT" << "\t" << "TAT" << "\t" << "WT" << "\t" << "CompT\n";

	for(int i=0;i<n;++i)
	{
		cout << P[i].pid << "\t" << P[i].at << "\t" << P[i].bt << "\t" << P[i].tat << "\t" << P[i].wt << "\t" << P[i].compt << "\n";
	}
}

int main() 
{
	int n,t_quantum;
	cout << "Enter the number of processes\n";
	cin >> n;
	cout << "Enter time quantum\n";
	cin >> t_quantum;

	struct process P[n];
	cout << "Enter pid\tat\tbt\n";
	for(int i=0;i<n;++i)
	{
		cin >> P[i].pid >> P[i].at >> P[i].bt;
		P[i].visited = false;
		P[i].rt = P[i].bt;
	}

	roundRobinScheduling(P,n,t_quantum);
	return 0;
}