#include <iostream>
#include <vector>

using namespace std;

int m, n, k;
int field[50][50];
int visit[50][50];

void init(){
    for(int i = 0;i < 50;i++){
        for(int j = 0;j < 50;j++){
            field[i][j] = 0;
            visit[i][j] = 0;
        }
    }
}

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};

void dfs(int x, int y){
    visit[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int xx = x+dx[i];
        int yy = y+dy[i];
        if(visit[xx][yy] == 1 || xx < 0 || yy < 0 || xx >= m || yy >= n){
            continue;
        }
        if(field[xx][yy] == 1){
            dfs(xx, yy);
        }
    }
}

int main()
{
    int ts;
    cin >> ts;
    for(int ii = 0;ii < ts;ii++){
        cin >> m >> n >> k;
        init();
        vector<pair<int, int>> coo;
        for(int i = 0;i < k;i++){
            int p, q;
            cin >> p >> q;
            field[p][q] = 1;
            coo.push_back({p, q});
        }
        int cnt = 0;
        for(int i = 0;i < coo.size();i++){
            //cout << "here";
            if(visit[coo[i].first][coo[i].second] == 0 && field[coo[i].first][coo[i].second] == 1){
                cnt++;
                dfs(coo[i].first, coo[i].second);
            }
        }
        cout << cnt << "\n";
    }
}
