#include <iostream>

using namespace std;

int arr[1005][1005];
int visit[1005][1005];
int n, m;
bool possible;

void dfs(int x, int y){
    //cout << x << " " << y << endl;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    visit[x][y] = 1;
    if(x == n-1) {
        possible = true;
        return;
    }
    for(int i = 0;i < 4;i++){
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        if(xx < 0 || yy < 0 || xx >= n || yy >= m || visit[xx][yy] == 1) continue;
        if(arr[xx][yy] == 0) dfs(xx, yy);
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        for(int j = 0;j < m;j++){
            arr[i][j] = temp[j] - 48;
        }
    }
    for(int i = 0;i < m;i++){
        if(arr[0][i] == 0 && visit[0][i] == 0){
            dfs(0, i);
        }
    }
    cout << ((possible) ? "YES" : "NO");
}
