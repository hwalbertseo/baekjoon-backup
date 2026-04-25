#include <iostream>

using namespace std;

int n;
int cnt = 0;
int arr[16][16];
int taken[16];

void dfs(int cur){
    if(cur >= n){
        cnt++;
        return;
    }
    for(int i = 0;i < n;i++){
        bool skip = false;
        if(taken[i] == 1){
            continue;
        }
        for(int j = 1;j < n;j++){
            if(i-j < 0 || cur - j < 0){
                continue;
            }
            if(arr[i-j][cur-j] == 1){
                skip = true;
            }
        }
        if(skip){
            continue;
        }
        for(int j = 1;j < n;j++){
            if(i+j >= n || cur - j < 0){
                continue;
            }
            if(arr[i+j][cur-j] == 1){
                skip = true;
            }
        }
        if(skip){
            continue;
        }
        arr[i][cur] = 1;
        taken[i] = 1;
        dfs(cur+1);
        arr[i][cur] = 0;
        taken[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    dfs(0);
    cout << cnt;
}
