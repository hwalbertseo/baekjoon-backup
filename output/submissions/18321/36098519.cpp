#include <iostream>
#include <vector>
#include <memory.h>
#define ll long long

using namespace std;

int n, m;
int arr[100005];
vector<pair<int, ll>> graph[100005];
bool visit[100005];
int possible = false;

void init(){
    possible = false;
    memset(visit, 0, sizeof(visit));
}

void dfs(int cur, ll mid, int goal){
    visit[cur] = 1;
    if(possible) return;
    if(cur == goal) {
        possible = true;
        return;
    }
    for(int i = 0;i < graph[cur].size();i++){
        int nxt = graph[cur][i].first;
        if(graph[cur][i].second >= mid && visit[nxt] != 1){
            dfs(nxt, mid, goal);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i < n+1;i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    ll hi = -1;
    ll lo = 2147483647;
    for(int i = 0;i < m;i++){
        ll p, q, r;
        cin >> p >> q >> r;
        graph[q].push_back({p, r});
        graph[p].push_back({q, r});
        if(r > hi) hi = r;
        if(r < lo) lo = r;
    }
    ll mx = hi;
/*
    for(int i = 1;i < n+1;i++){
        cout << i << ": ";
        for(int j = 0;j < graph[i].size();j++){
            cout << "(" << (graph[i][j].first) << " " << graph[i][j].second << ") ";
        }
        cout << endl;
    }

*/  //cout << endl;
    bool go = true;
    for(int i = 1;i < n+1;i++){
        if(i != arr[i]) {
            go = false;
            break;
        }
    }
    if(go) {
        cout << -1;
        return 0;
    }
    while(lo < hi){
        ll mid = (lo + hi)/2 + 1;
        for(int i = 1;i < n+1;i++){
            init();
            //cout << mid << " " << i << " " << arr[i] << "\n" << lo << " " << hi << endl;
            dfs(i, mid, arr[i]);
            if(!possible) break;
        }
        if(!possible){
            hi = mid-1;
        }
        else{
            lo = mid;
        }
    }
    cout << hi;
}
/*

4 4
3 2 1 4
1 2 10
1 3 7
2 3 10
2 4 3
*/
