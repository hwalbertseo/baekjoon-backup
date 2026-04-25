#include <iostream>

using namespace std;

int n, m;
int arr[100005];
bool visit[100005];

void dfs(int cur, int cnt){
    if(cnt == m){
        for(int i = 0;i < m;i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = cur;i <= n;i++){
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
    cin >> n >> m;
    dfs(1, 0);
}
