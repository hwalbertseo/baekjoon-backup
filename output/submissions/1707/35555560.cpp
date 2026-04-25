#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[20005];
int visit[20005];
bool possible = true;
int n;

void init(){
    for(int i = 0;i <= n;i++){
        visit[i] = 0;
        arr[i].empty();
    }
    possible = true;
}

void dfs(int cur){
    for(int i = 0;i < arr[cur].size();i++){
        if(visit[arr[cur][i]] == 0){
            visit[arr[cur][i]] = (visit[cur])%2 + 1;
            dfs(arr[cur][i]);
        }
        else if(visit[arr[cur][i]] == visit[cur]){
            possible = false;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int ts;
    cin >> ts;
    for(int i = 0;i < ts;i++){
        int m;
        cin >> n >> m;
        for(int j =0;j < m;j++){
            int p, q;
            cin >> p >> q;
            arr[p].push_back(q);
            arr[q].push_back(p);
        }
        for(int j = 1;j <= n;j++){
            if(visit[j] == 0){
                visit[j] = 1;
                dfs(j);
            }
        }
        cout << ((possible) ? "YES" : "NO") << "\n";
        init();
    }

}
