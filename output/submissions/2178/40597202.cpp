#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[105][105];
int visit[105][105];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

struct coo{
    int x, y;
};

void bfs(int sx, int sy){
    queue<coo> q;
    coo temp;
    temp.x = sx;
    temp.y = sy;
    q.push(temp);
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int t = visit[x][y];
        if(x == n-1 && y == m-1){
            cout << t + 1;
            return;
        }
        q.pop();
        for(int i = 0;i < 4;i++){
            int xx = x +dx[i];
            int yy = y + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m){
                continue;
            }
            else if(arr[xx][yy] == 0){
                continue;
            }
            else if(visit[xx][yy] > 0 && visit[xx][yy] <= t){
                continue;
            }
            temp.x = xx;
            temp.y = yy;
            visit[xx][yy] = visit[x][y]+1;
            q.push(temp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        string s;
        cin >> s;
        for(int j = 0;j < m;j++){
            arr[i][j] = s[j]-'0';
        }
    }
    bfs(0, 0);
}
