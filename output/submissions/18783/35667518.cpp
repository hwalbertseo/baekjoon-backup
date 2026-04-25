#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[100005];
int visit[100005];
vector<int> path;
vector<int> cycles[100005];
int n, m, k;

void dfs(int cur){
    visit[cur] = 1;
    path.push_back(cur);
    int nxt = arr[cur][0];
    if(visit[nxt] == 1){
        int idx = -1;
        for(int i = 0;i < path.size();i++){
            if(nxt == path[i]){
                idx = i;
            }
        }
        if(idx != -1){
            int mod = path.size() - idx;
            for(int i = idx;i < path.size();i++){
                //cout << path[i] << " ";
                for(int j = 0;j < mod;j++){
                    //cout << "ent\n";
                    int curind = (i-idx + j)%mod + idx;
                    //cout << "c  " << curind << "\n";
                    cycles[path[i]].push_back(path[curind]);
                }
            }
        }
    }
    else{
        dfs(nxt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    int temparr[n+1];
    for(int i = 1;i <= n;i++){
        temparr[i] = i;
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        for(int j = q-p;j > (q-p)/2;j--){
            int temp = temparr[q-j];
            temparr[q-j] = temparr[j+p];
            temparr[j+p] = temp;
        }
    }
    for(int i = 1;i <= n;i++){
        arr[i].push_back(temparr[i]);
    }
    for(int i = 1;i <= n;i++){
        if(visit[i] != 1){
            dfs(i);
        }
        path.clear();
    }
    for(int i = 1;i <= n;i++){
        int siz = k%(cycles[i].size());
        cout << cycles[i][siz] << "\n";
    }
}
