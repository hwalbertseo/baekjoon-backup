#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100005];
int ans[100005];

void dfs(int cnt, int prev){
    if(cnt >= m){
        for(int i = 0;i < m;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = prev;i < n;i++){
        ans[cnt] = arr[i];
        dfs(cnt+1, i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    dfs(0, 0);
}
