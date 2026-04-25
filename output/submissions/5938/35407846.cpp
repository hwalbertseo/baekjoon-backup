#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
bool check[255];
int cnt;

void dfs(vector<vector<int>> v, int cur){
    if(check[cur]) return;
    check[cur] = true;
    cnt++;
    for(int i = 0;i < v[cur].size();i++){
        dfs(v, v[cur][i]);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >>n >> m;

    for(int i = 0;i <= n;i++){
        vector<int> temp;
        v.push_back(temp);
    }
    for(int i = 0;i <m;i++){
        int p, q;
        cin >> p >> q;
        v[p].push_back(q);
        v[q].push_back(p);
    }
    dfs(v, 1);
    for(int i = 1;i <= n;i++){
        if(!check[i]) cout << i << "\n";
    }
}
