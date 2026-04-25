#include <iostream>

using namespace std;

int n = 6;
int p;
int inp[100005];
int ans[100005];
int visit[100005];

void dfs(int now, int cnt){
    //cout << now << " " << cnt << endl;
    if(cnt >= n){
        for(int i = 0;i < n;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = now;i < p;i++){
        if(visit[i] == 1){
            continue;
        }
        visit[i] = 1;
        ans[cnt] = inp[i];
        //cout << cnt << " " <<i << endl;
        dfs(i, cnt+1);
        visit[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    while(1){
        cin >> p;
        if(p == 0){
            break;
        }
        else{
            for(int i = 0;i < p;i++){
                cin >> inp[i];
            }
        }
        dfs(0, 0);
        cout << "\n";
    }
}
