#include <iostream>
#include <queue>
#include <vector>
#include <set>

using namespace std;

int n, m;
char arr[1505][1505];
pair<int, int> ss[1505][1505];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int visit[1505][1505];
int bfs[1505][1505];
char state[1505][1505];
vector<pair<int, int>> v;
queue<pair<int, int>> wat;
set<pair<int, int>> best;

pair<int, int> srch(int x, int y){
    if(ss[x][y].first == x && ss[x][y].second == y){
        return {x, y};
    }
    ss[x][y] = srch(ss[x][y].first, ss[x][y].second);
    return ss[x][y];
}

void comb(int x1, int y1, int x2, int y2){
    pair<int, int> p = srch(x1, y1);
    pair<int, int> q = srch(x2, y2);

    if(p.first == q.first && p.second == q.second){
        return;
    }
    ss[p.first][p.second] = q;
}

void init(){
    for(int i = 0;i < 1505;i++){
        for(int j = 0;j < 1505;j++){
            visit[i][j] = 0;
            bfs[i][j] = 0;
        }
    }
}

void melt(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    while(!q.empty()){
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();
        if(visit[xx][yy] == 1){
            continue;
        }
        visit[xx][yy] = 1;
        for(int i = 0;i < 4;i++){
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if(visit[nx][ny] == 1){
                continue;
            }
            if(state[nx][ny] == 'X'){
                arr[nx][ny] = '.';

                for(int i = 0;i < 4;i++){
                    int tx = nx + dx[i];
                    int ty = ny + dy[i];
                    if(arr[tx][ty] == '.' || arr[tx][ty] == 'L'){
                        comb(tx, ty, nx, ny);
                    }
                }

                continue;

            }
            q.push({nx, ny});
        }
    }
}

void make(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    best.insert({x, y});
    while(!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        if(visit[curx][cury] == 1){
            continue;
        }
        visit[curx][cury] = 1;
        ss[curx][cury] = {x, y};
        for(int i = 0;i < 4;i++){
            int xx = curx + dx[i];
            int yy = cury + dy[i];
            if(xx < 0 || xx >= n || yy < 0 || yy >= m){
                continue;
            }
            if(visit[xx][yy] == 1){
                continue;
            }
            if(arr[xx][yy] == 'X'){
                continue;
            }
            q.push({xx, yy});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        for(int j = 0;j < m;j++){
            arr[i][j] = temp[j];
            if(temp[j] == 'L'){
                v.push_back({i, j});
                wat.push({i, j});
            }
            else if(temp[j] == '.'){
                wat.push({i, j});
            }
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            ss[i][j].first = i;
            ss[i][j].second = j;
        }
    }
    while(!wat.empty()){
        int i = wat.front().first;
        int j = wat.front().second;
        wat.pop();
        if(visit[i][j] != 1){
            if(arr[i][j] == '.' || arr[i][j] == 'L'){
                make(i, j);
            }
        }
    }
    int turn = 0;
    while(1){
        int coo1x = v[0].first;
        int coo1y = v[0].second;
        pair<int, int> coo1 = srch(coo1x, coo1y);
        int coo2x = v[1].first;
        int coo2y = v[1].second;
        pair<int, int> coo2 = srch(coo2x, coo2y);

        if(coo1.first == coo2.first && coo1.second == coo2.second){
            cout << turn;
            break;
        }

        init();
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                state[i][j] = arr[i][j];
            }
        }
        for(pair<int, int> p : best){
            if(bfs[p.first][p.second] == 1){
                continue;
            }
            bfs[p.first][p.second] = 1;
            melt(p.first, p.second);
        }
        turn++;
        /*
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cout << "(" << ss[i][j].first << "," << ss[i][j].second << ") ";
            }
            cout << endl;
        }

        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }

        cout << endl;
        /*
        if(turn == 10){
            break;
        }
        */

    }
}
