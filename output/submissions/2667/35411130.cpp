#include <iostream>
#include <algorithm>

using namespace std;

int arr[30][30];
int visit[30][30];
int housenum[30];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int cnt = 0;
int n;

void dfs(int x, int y){
    visit[x][y] = 1;
    housenum[cnt]++;
    for(int i = 0;i < 4;i++){
        int cx = dx[i] + x;
        int cy = dy[i] + y;
        if(cx < 0 || cy < 0 || cx >= n || cy >= n || visit[cx][cy] == 1) continue;
        if(arr[cx][cy] == 1){
            dfs(cx, cy);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        for(int j = 0;j < n;j++){
            arr[i][j] = temp[j] - 48;
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(arr[i][j] == 1 && visit[i][j] == 0) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << "\n";
    sort(housenum, housenum+cnt+1);
    for(int i = 1;i <= cnt;i++){
        cout << housenum[i] << "\n";
    }
}
