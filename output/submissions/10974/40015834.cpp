#include <iostream>

using namespace std;

int n;
int arr[100005];
int visit[100005];

void dfs(int now, int cnt){
    if(cnt >= n){
        for(int i = 0;i < n;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 1;i <= n;i++){
        if(visit[i] == 1){
            continue;
        }
        visit[i] = 1;
        arr[cnt] = i;
        dfs(i, cnt+1);
        visit[i] = 0;

    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    dfs(1, 0);
}
