#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
int ans[100005];

void dfs(int cnt){
    if(cnt >= m){
        for(int i = 0;i < m;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0;i < n;i++){
        if(ans[cnt] == arr[i]){
            continue;
        }
        ans[cnt] = arr[i];
        dfs(cnt+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int p;
        cin >> p;
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end());
    dfs(0);
}
