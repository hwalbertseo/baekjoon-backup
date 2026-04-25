#include <iostream>
#include <vector>

using namespace std;

vector<pair<char, int>> arr[100005];
int visit[100005];
int n;
long long blobnum = 0;
bool impossible = false;

void dfs(int cur){
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i].second;
        if(visit[nxt] >= 1){
            if(arr[cur][i].first == 'S'){
                if(visit[cur] != visit[nxt]){
                    impossible = true;
                }
            }
            else if(arr[cur][i].first == 'D'){
                if(visit[cur] == visit[nxt]){
                    impossible = true;
                }
            }
        }
        else{
            if(arr[cur][i].first == 'S'){
                visit[nxt] = visit[cur];
            }
            else{
                if(visit[cur] == 1) visit[nxt] = 2;
                else visit[nxt] = 1;
            }
            dfs(nxt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cout.tie(0); cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        char p;
        int q, r;
        cin >> p >> q >> r;
        arr[q].push_back({p, r});
        arr[r].push_back({p, q});
    }
    for(int i = 1;i <= n;i++){
        if(visit[i] == 0 && impossible == false){
            visit[i] = 1;
            blobnum++;
            dfs(i);
        }
    }
    if(impossible) cout << 0;
    else {
        cout << 1;
        for(int i = blobnum;i > 0;i--){
            cout << 0;
        }
    }
}
