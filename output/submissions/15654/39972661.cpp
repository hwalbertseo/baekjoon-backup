#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100005];
int inp[100005];
bool visit[100005];

void dfs(int cur, int cnt){
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0;i < n;i++){
        if(visit[i] == 1){
            continue;
        }
        visit[i] = 1;
        arr[cnt] = inp[i];
        dfs(i, cnt+1);
        visit[i] = 0;
    }

}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> inp[i];
    }
    sort(inp, inp+n);
    dfs(0, 0);
}
