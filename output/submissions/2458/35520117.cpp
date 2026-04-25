#include <iostream>
#include <vector>

using namespace std;

vector<int> upper[505];
int visit[505];
int cnt;
vector<int> lower[505];
int n;

void init(){
    for(int i = 0;i < 505;i++){
        visit[i] = 0;
    }
}

void dfs(vector<int> v[], int cur){
    visit[cur] = 1;
    for(int i = 0;i < v[cur].size();i++){
        if(visit[v[cur][i]] == 0){
            //cout << "v: " << v[cur][i] << "\n";
            cnt++;
            dfs(v, v[cur][i]);
        }
    }
}

int main()
{
    int m;
    int num = 0;
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        upper[p].push_back(q);
        lower[q].push_back(p);
    }
    for(int i = 1;i <= n;i++){
        cnt = 0;
        init();
        dfs(upper, i);
        dfs(lower, i);
        //cout << i << " " << cnt << "\n";
        if(cnt == n-1) {
            //cout << i << " ";
            num++;
        }
    }
    cout << num;
}
