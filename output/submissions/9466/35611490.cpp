#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[100005];
int visit[100005];
int n;
vector<int> path;
int pos = 0;

void init(){
    pos = 0;
    for(int i = 0;i <= n;i++){
        arr[i].clear();
        visit[i] = 0;
    }
}

void dfs(int cur){
    visit[cur] = 1;
    path.push_back(cur);
    int nxt = arr[cur][0];
    if(visit[nxt] == 1){
        int idx = -1;
        for(int i = 0;i < path.size();i++){
            if(path[i] == nxt){
                idx = i;
            }
        }
        if(idx != -1){
            pos += path.size() - idx;
        }
    }
    else{
        dfs(nxt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    for(int i = 0;i < tc;i++){
        cin >> n;
        for(int j = 1;j <= n;j++){
            int temp;
            cin >> temp;
            arr[j].push_back(temp);
        }
        for(int j = 1;j <= n;j++){
            if(visit[j] != 1){
                dfs(j);
            }
            path.clear();
        }
        cout << n - pos << "\n";
        init();
    }
}
