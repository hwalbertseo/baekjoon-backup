#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[100005];
vector<pair<int, int>> graph[100005];
int visit[100005];
int possible = false;

void init(){
    possible = false;
    for(int i = 0;i < n+5;i++){
        visit[i] = 0;
    }
}

void dfs(int cur, int mid, int goal){
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
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i < n+1;i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
    }
    int hi = -1;
    int lo = 2147483647;
    for(int i = 0;i < m;i++){
        int p, q, r;
        cin >> p >> q >> r;
        graph[q].push_back({p, r});
        graph[p].push_back({q, r});
        if(r > hi) hi = r;
        if(r < lo) lo = r;
    }
    int mx = hi;
/*
    for(int i = 1;i < n+1;i++){
        cout << i << ": ";
        for(int j = 0;j < graph[i].size();j++){
            cout << "(" << (graph[i][j].first) << " " << graph[i][j].second << ") ";
        }
        cout << endl;
    }

*/  //cout << endl;
    hi++;
    while(lo < hi){
        int mid = (lo + hi)/2;
        for(int i = 1;i < n+1;i++){
            init();
            //cout << mid << " " << i << " " << arr[i] << "\n";
            dfs(i, mid, arr[i]);
            if(!possible) break;
        }
        if(!possible){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if(hi <= mx) cout << hi-1;
    else cout << -1;
}
/*

4 4
3 2 1 4
1 2 10
1 3 7
2 3 10
2 4 3
*/
