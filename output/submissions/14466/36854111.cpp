#include <iostream>
#include <vector>

using namespace std;

int n, k, r;
int arr[200][200];
int visit[200][200];
vector<pair<int, int>> v;

int dx[4] = {-2, 0, 0, 2};
int pathx[4] = {-1, 0, 0, 1};
int pathy[4] = {0, -1, 1, 0};
int dy[4] = {0, -2, 2, 0};

void dfs(int x, int y, int f){
    visit[x][y] = f;
    for(int i = 0;i < 4;i++){
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        int px = pathx[i] + x;
        int py = pathy[i] + y;
        if(xx < 0 || yy < 0 || xx > (n-1)*2 || yy > (n-1)*2){
            continue;
        }
        if(visit[xx][yy] != 0 || arr[px][py] == -1){
            continue;
        }
        dfs(xx, yy, f);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> r;
    for(int i = 0;i < r;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        x1 *= 2; x2 *= 2; y1 *= 2; y2 *= 2;
        if(x1 == x2){
            if(y1 > y2){
                arr[x1][y1-1] = -1;
            }
            else{
                arr[x1][y1+1] = -1;
            }
        }
        else if(x1 > x2){
            arr[x1-1][y1] = -1;
        }
        else{
            arr[x2-1][y1] = -1;
        }
    }
    int f = 1;
    for(int i = 0;i <= (n-1)*2;i = i + 2){
        for(int j = 0;j <= (n-1)*2;j = j + 2){
            if(visit[i][j] == 0){
                dfs(i, j, f);
                f++;
            }
        }
    }

    for(int i = 0;i < k;i++){
        int p, q;
        cin >> p >> q;
        v.push_back({(p-1)*2, (q-1)*2});
    }
    int cnt = 0;
    for(int i = 0;i < k;i++){
        for(int j = i+1;j < k;j++){
            if(visit[v[i].first][v[i].second] != visit[v[j].first][v[j].second]){
                cnt++;
            }
        }
    }
    cout << cnt;
}
