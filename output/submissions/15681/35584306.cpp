#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[100005];
int visit[100005];
int subTree[100005];
int n, r;

void dfs(int cur, vector<int> path){
    visit[cur] = 1;
    subTree[cur]++;
    path.push_back(cur);
    for(int i = 0;i < arr[cur].size();i++){
        int nxt = arr[cur][i];
        if(visit[nxt] == 0){
            for(int i = 0;i < path.size();i++){
                subTree[path[i]]++;
            }
            dfs(nxt, path);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int q;
    cin >> n >> r >> q;
    for(int i = 1;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[p].push_back(q);
        arr[q].push_back(p);
    }
    vector<int> path;
    dfs(r, path);
    for(int i = 0;i < q;i++){
        int temp;
        cin >> temp;
        cout << subTree[temp] << "\n";
    }
}
