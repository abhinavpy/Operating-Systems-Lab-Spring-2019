#include<bits/stdc++.h>
using namespace std;

struct node {
    int distance;
    bool accessed;
};

void calculateDifference(vector<int> queue, int head, struct node *diff, int n)
{
    for(int i=0; i < n; ++i)
    {
        diff[i].distance = abs(queue[i] - head);
    }
}

int findMin(node diff[], int n)
{
    int index = -1, minimum = INT_MAX;
    for(int i=0; i < n; ++i)
    {
        if(!diff[i].accessed && minimum > diff[i].distance)
        {
            minimum = diff[i].distance;
            index = i;
        }
    }
    return index;
}

void shortestSeekTimefirst(vector<int> request, int head)
{
    if(request.size() == 0)
    {
        return;
    }

    struct node* diff = (struct node*)malloc(sizeof(struct node) * (request.size()));

    for(int i=0; i < request.size(); ++i)
    {
        diff[i].distance = 0;
        diff[i].accessed = false;
    }

    int seek_count = 0;

    vector<int> seek_sequence(request.size() + 1);

    for(int i=0; i< request.size(); ++i)
    {
        seek_sequence[i] = head;

        calculateDifference(request, head, diff, request.size());

        int index = findMin(diff, request.size());

        diff[index].accessed = true;

        seek_count += diff[index].distance;

        head = request[index];
    }

    seek_sequence[request.size() - 1] = head;

    cout << "Total number of seek operations: " << seek_count << endl;

    cout << "Seek sequence is :" << endl;

    for(int i=0; i < request.size(); ++i)
    {
        cout << seek_sequence[i] << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of disk accesses" << endl;

    cin >> n;

    vector <int> arr(n);

    for(int i=0; i < n; ++i) 
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    cout << "Enter the position of the disk head\n";
    int head;
    cin >> head;

    shortestSeekTimefirst(arr, head);
    return 0;
}