#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> arr[5005];
int table[5005][5005];
int visit[5005];

void dfs(int cur, int worst, int init){
    visit[cur] = 1;
    if(table[init][cur] == 0 && init != cur){
        table[init][cur] = worst;
        table[cur][init] = worst;
    }
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i].first;
        int weight = arr[cur][i].second;
        if(visit[nxt] != 1){
            if(worst > weight){
                dfs(nxt, weight, init);
            }
            else{
                dfs(nxt, worst, init);
            }
        }
    }
}

void initialize(){
    for(int i = 1;i <= 5000;i++){
        visit[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 0;i < n-1;i++){
        int p, q, r;
        cin >> p >> q >> r;
        arr[p].push_back({q, r});
        arr[q].push_back({p, r});
    }
    for(int i = 1;i <= n;i++){
        dfs(i, 2e9, i);
        initialize();
    }
    for(int i = 0;i < m;i++){
        int k, v;
        cin >> k >> v;
        int cnt = 0;
        for(int i = 1;i <= n;i++){
            if(table[v][i] >= k){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
