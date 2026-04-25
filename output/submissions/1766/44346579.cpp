#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int ind[32005];
vector<int> graph[32005];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        graph[p].push_back(q);
        ind[q]++;
    }
    for(int i = 1;i <= n;i++){
        if(ind[i] == 0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        cout << cur << " ";
        for(int i = 0;i < graph[cur].size();i++){
            int nxt = graph[cur][i];
            ind[nxt]--;
            if(ind[nxt] == 0){
                pq.push(nxt);
            }
        }
    }
}
