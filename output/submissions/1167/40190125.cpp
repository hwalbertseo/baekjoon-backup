#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> arr[100005];
int visit[100005];
int furthest = 0, dist = -1;

void dfs(int cur, int curdis){
    visit[cur] = 1;
    if(curdis > dist){
        dist = curdis;
        furthest = cur;
    }
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i].first;
        if(visit[nxt] != 1){
            dfs(nxt, curdis + arr[cur][i].second);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        int z;
        cin >> z;
        while(1){
            int p, q;
            cin >> p;
            if(p == -1){
                break;
            }
            cin >> q;
            arr[z].push_back({p, q});
        }
    }
    dfs(1, 0);
    for(int i = 0;i < 100005;i++){
        visit[i] = 0;
    }
    dist = -1;
    dfs(furthest, 0);
    cout << dist;
}
