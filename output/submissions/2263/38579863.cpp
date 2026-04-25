#include <iostream>

using namespace std;

int bt[100003][2];
int pf[100003];
int inf[100003];

void dfs(int cur){
    int left = bt[cur][0];
    int right = bt[cur][1];
    cout << cur << " ";
    if(left != 0){
        dfs(left);
    }
    if(right != 0){
        dfs(right);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int p;
        cin >> p;
        inf[p] = i+1;
    }
    for(int i = n-1;i >= 0;i--){
        cin >> pf[i];
    }
    int fnode = pf[0];
    for(int i = 1;i < n;i++){
        int cur = pf[i];
        int f = fnode;
        while(1){
            if(inf[f] > inf[cur]){
                if(bt[f][0] == 0){
                    bt[f][0] = cur;
                    break;
                }
                else{
                    f = bt[f][0];
                    continue;
                }
            }
            else{
                if(bt[f][1] == 0){
                    bt[f][1] = cur;
                    break;
                }
                else{
                    f = bt[f][1];
                    continue;
                }
            }
        }
    }
    dfs(fnode);
}
