#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[100005];
int visit[100005];
int parent[100005];
int n;

void dfs(int cur){
    visit[cur] = 1;
    for(int i = 0;i < arr[cur].size();i++){
        if(visit[arr[cur][i]] == 1){
            continue;
        }
        else{
            parent[arr[cur][i]] = cur;
            dfs(arr[cur][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[p].push_back(q);
        arr[q].push_back(p);
    }
    dfs(1);
    for(int i = 2;i <= n;i++){
        cout << parent[i] << "\n";
    }
}
