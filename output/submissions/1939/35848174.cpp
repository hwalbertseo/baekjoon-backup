#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> arr[10005];
vector<int> path;
int n;
int s, e;
int possible = false;

void dfs(int cur, int wei, int turn){
    if(cur == e) {
        possible = true;
        return;
    }
    path.push_back(cur);
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i].first;
        int weight = arr[cur][i].second;
        if(weight > wei){
            continue;
        }
        bool flag = false;
        for(int j = 0;j < path.size();j++){
            if(path[j] == nxt){
                flag = true;
            }
        }
        if(flag) continue;
        else if(!flag){
            dfs(nxt, wei, turn+1);
        }
        path.erase(path.begin() + turn, path.end());
    }
}

int main()
{
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
        dfs(s, mid, 0);
        if(possible){
            lo = mid;
        }
        else{
            hi= mid-1;
        }
    }
    cout << lo;
}
