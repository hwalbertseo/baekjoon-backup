#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> v[100005];
int ind[100005];
queue<int> q;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        v[p].push_back(q);
        ind[q]++;
    }
    for(int i = 1;i <= n;i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for(int i = 0;i < v[cur].size();i++){
            int nxt = v[cur][i];
            ind[nxt]--;
            if(ind[nxt] == 0){
                q.push(nxt);
            }
        }
    }
}
