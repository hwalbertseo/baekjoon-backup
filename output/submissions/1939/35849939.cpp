#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr[10005];
int visit[10005];
int n;
int s, e;
bool possible = false;

void init(){
    possible = false;
    for(int i = 0;i < 10005;i++){
        visit[i] = 0;
    }
}

void dfs(int cur, int wei){
    visit[cur] = 1;
    if(cur == e) {
        possible = true;
        return;
    }
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i].first;
        int weight = arr[cur][i].second;
        if(weight > wei){
            continue;
        }
        if(visit[nxt] == 0){
            dfs(nxt, wei);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int m;
    cin >> n >> m;
    int maxweight = -1;;
    for(int i = 0;i < m;i++){
        int p, q, r;
        cin >> p >> q >> r;
        if(maxweight < r){
            maxweight = r;
        }
        arr[p].push_back({q, r});
        arr[q].push_back({p, r});
    }
    cin >> s >> e;
    int lo = 1;
    int hi = maxweight;
    while(lo < hi){
        int mid = (lo + hi)/2 + 1;
        init();
        dfs(s, mid);
        if(possible){
            lo = mid;
        }
        else{
            hi= mid-1;
        }
    }
    cout << lo;
}
