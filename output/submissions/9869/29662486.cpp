#include <iostream>
#include <queue>

using namespace std;

struct node {
    int gallon;
    int time;
};

struct cmp{
    bool operator()(node t, node u){
        if(t.time == u.time){
            return t.gallon < u.gallon;
        }
        else{
            return t.time > u.time;
        }
    }
};

int main()
{
    //get input
    int n = 0;
    cin >> n;
    //int arr[n][2];
    priority_queue<node, vector<node>, cmp> pq;
    for(int i = 0;i < n;i++){
        struct node newnode;
        cin >> (newnode.gallon);
        cin >> (newnode.time);
        // cout << newnode.gallon << " " << newnode.time << endl;
        pq.push(newnode);
        //cout << pq.top().gallon << endl;
    }
    int time = 0;
    int sum = 0;
    for(int i = 0;i < n;i++) {
        if(time < pq.top().time){
           sum += pq.top().gallon;
        }
        pq.pop();
        time++;
    }
    cout << sum;
}
