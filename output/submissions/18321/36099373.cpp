#include <iostream>
#include <vector>
#define ll long long

using namespace std;

int n, m;
int arr[100005];
vector<pair<int, ll>> graph[100005];
bool found[100005];
int visit[100005];
//int iter = 0;
int cnt;
int possible = true;

void init(){
    possible = true;
    for(int i = 0;i < n+2;i++){
        visit[i] = 0;
    }
}

void initfound(){
    for(int i = 0;i < n+2;i++){
        found[i] = 0;
    }
}

void dfs1(int cur, ll mid){
    //cout << "cur: " << cur << " " << mid << "\n";
    visit[cur] = 1;
    found[arr[cur]] = 1;
    for(int i = 0;i < graph[cur].size();i++){
        int nxt = graph[cur][i].first;
        if(graph[cur][i].second >= mid && visit[nxt] != 1){
            dfs1(nxt, mid);
        }
    }
}

void dfs2(int cur, ll mid){
    //cout << "cur: " << cur << " " << mid << "\n";
    visit[cur] = 2;
    if(found[cur] == 0) possible = false;
    for(int i = 0;i < graph[cur].size();i++){
        int nxt = graph[cur][i].first;
        if(graph[cur][i].second >= mid && visit[nxt] != 2){
            dfs2(nxt, mid);
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
        cnt = 0;
        init();
        for(int i = 1;i < n+1;i++){
            //cout << mid << " " << i << " " << arr[i] << "\n" << lo << " " << hi << endl;
            //cout << i << "\n";
            if(visit[i] == 0){
                dfs1(i, mid);
                dfs2(i, mid);
                initfound();
            }
        }
        if(cnt == n) possible = true;
        //cout << mid << " " << cnt << "\n";
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
