#include <iostream>

using namespace std;

int arr[105];
int ans[105];
int top[105];
int bot[105];
bool impossible = false;

void init(){
    for(int i = 0;i <= 100;i++){
        top[i] = 0;
        bot[i] = 0;
    }
    impossible = false;
}

void solve(int k){
    //cout << k << endl;
    if(impossible){
        return;
    }
    if(top[k] == 1){
        for(int i = 1;i <= 100;i++){
            if(top[i] == 1 && bot[i] == 0){
                impossible = true;
                return;
            }
        }
        for(int j = 1;j <= 100;j++){
            if(top[j] == 1) ans[j] = 1;
            impossible = true;
        }
    }
    top[k] = 1;
    bot[arr[k]] = 1;
    solve(arr[k]);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
    }
    for(int i = 1;i <=n;i++){
        if(ans[i]){
            continue;
        }
        solve(i);
        init();
    }
    int cnt = 0;
    for(int i = 1;i <=n;i++){
        if(ans[i]){
            cnt++;
        }
    }
    cout << cnt << "\n";
    for(int i = 1;i <=n;i++){
        if(ans[i]){
            cout << i << "\n";
        }
    }
}
