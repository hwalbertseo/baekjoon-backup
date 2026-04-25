#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1005][1005];
bool visit[1005][1005];
int sm[1005][1005];


int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

struct coo{
    int first;
    int second;
    int cnt;
};

queue<coo> q;

void init(){
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            visit[i][j] = 0;
        }
    }
    while(!q.empty()){
        q.pop();
    }
}

void bfs(int x, int y){
    q.push({x, y, 0});
    while(!q.empty()){
        //cout << q.size() << endl;
        int ex = q.front().first;
        int ey = q.front().second;
        int cnt = q.front().cnt;
        if(sm[ex][ey] > cnt || sm[ex][ey] == 0){
            sm[ex][ey] = cnt;
        }
        for(int i = 0;i < 4;i++){
            int xx = ex + dx[i];
            int yy = ey + dy[i];
            if(xx < 0 || yy < 0 || xx >= m || yy >= n){
                //cout << xx << " " << yy << " cut \n";
                continue;
            }
            else if(visit[xx][yy] == 1 || arr[xx][yy] != 0){
                //cout << xx << " " << yy << " cut \n";
                continue;
            }
            else{
                //cout << "pushed";
                visit[xx][yy] = 1;
                q.push({xx, yy, cnt+1});
            }
        }
        q.pop();
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(arr[i][j] == 1){
                init();
                bfs(i, j);
            }
        }
    }
    int maxcnt = -1;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(sm[i][j] == 0 && arr[i][j] == 0){
                cout << -1;
                return 0;
            }
            else{
                if(maxcnt < sm[i][j]){
                    maxcnt = sm[i][j];
                }
            }
        }
    }
    cout << maxcnt;
}
