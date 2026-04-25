#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int>> v[101][101];
int visit[101][101];
int light[101][101];
int fin[101][101];
int cnt = 1;
bool changed = true;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void init(){
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= n;j++){
            visit[i][j] = 0;
        }
    }
    changed = false;
}

void dfs(int x, int y){
    visit[x][y] = 1;
    if(fin[x][y] == 0){
        //cout << x << " " << y << endl;
        for(int i = 0;i < v[x][y].size();i++){
            pair<int, int> temp = v[x][y][i];
            if(light[temp.first][temp.second] == 0){
                //cout << "in2";
                changed = true;
                light[temp.first][temp.second] = 1;
                cnt++;
            }
        }
        fin[x][y] = 1;
    }
    for(int i = 0;i < 4;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(xx < 0 || yy < 0 || xx >= n || yy >= n){
            continue;
        }
        if(visit[xx][yy] == 1 || light[xx][yy] == 0){
            continue;
        }
        dfs(xx, yy);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        v[x-1][y-1].push_back({a-1, b-1});
    }
    light[0][0] = 1;
    while(changed){
        init();
        dfs(0, 0);
    }
    /*
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            cout << light[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << cnt;
}
