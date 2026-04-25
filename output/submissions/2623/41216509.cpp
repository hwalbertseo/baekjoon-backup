#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> arr[10005];
int ind[10005];
int out[10005];
vector<int> ans;

void topsort(){
    queue<int> q;
    for(int i = 1;i <= n;i++){
        if(ind[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        ans.push_back(cur);
        q.pop();
        for(int i = 0;i < arr[cur].size();i++){
            int nxt = arr[cur][i];
            //cout << nxt << " ";
            ind[nxt]--;
            if(ind[nxt] == 0){
                q.push(nxt);
            }
        }
        //cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int p;
        cin >> p;
        int bef = 0;
        for(int j = 0;j < p;j++){
            int q;
            cin >> q;
            if(j == 0){
                out[q]++;
            }
            else{
                arr[bef].push_back(q);
                ind[q]++;
                if(j != p-1){
                    out[q]++;
                }
            }
            bef = q;
        }
    }
    /*
    for(int i = 1;i <= n;i++){
        cout << ind[i] << "\n";
    }
    cout << endl;
    */
    topsort();
    if(ans.size() != n){
        cout << 0;
    }
    else{
        for(int i = 0;i < ans.size();i++){
            cout << ans[i] << "\n";
        }
    }
}
