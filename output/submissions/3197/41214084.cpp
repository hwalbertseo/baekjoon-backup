#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int r, c;
char arr[1505][1505];
vector<pair<int, int>> dist[50000];
vector<pair<int, int>> dots;
pair<int, int> mm[1505][1505];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, 1, -1, 0};
int visit[1505][1505] = {0,};

vector<pair<int, int>> swan;

pair<int, int> srch(int x1, int y1){
    if(mm[x1][y1].first == x1 && mm[x1][y1].second == y1){
        return {x1, y1};
    }
    return mm[x1][y1] = srch(mm[x1][y1].first, mm[x1][y1].second);
}

void comb(int x1, int y1, int x2, int y2){
    pair<int, int> p, q;
    p = srch(x1, y1);
    q = srch(x2, y2);

    if(p.first == q.first && p.second == q.second){
        return;
    }

    mm[p.first][p.second] = q;
}

void init(){
    //int visit[1505][1505] = {0,};
    queue<pair<int, int>> q;
    q.push({0, 0});
    while(!q.empty()){
        //cout << "inf";
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        if(visit[curx][cury] == 1){
            continue;
        }
        visit[curx][cury] = 1;
        for(int i = 0;i < 4;i++){
            int nxtx = curx+dx[i];
            int nxty = cury+dy[i];
            if(nxtx < 0 || nxtx >= r || nxty < 0 || nxty >= c){
                continue;
            }
            else if(visit[nxtx][nxty] == 1){
                continue;
            }
            if(arr[curx][cury] != 'X' && arr[nxtx][nxty] != 'X'){
                comb(curx, cury, nxtx, nxty);
            }
            else if(arr[curx][cury] != 'X' && arr[nxtx][nxty] == 'X'){
                dots.push_back({nxtx, nxty});
            }
            else if(arr[curx][cury] == 'X' && arr[nxtx][nxty] != 'X'){
                dots.push_back({curx, cury});
            }
            q.push({nxtx, nxty});
        }
    }
    for(int i = 0;i < 1505;i++){
        for(int j = 0;j < 1505;j++){
            visit[i][j] = 0;
        }
    }
}

void bfs(){
    queue<pair<pair<int, int>, int>> q;
    //int visit[1505][1505] = {0,};
    for(int i = 0;i < dots.size();i++){
        q.push({dots[i], 1});
    }
    while(!q.empty()){
        int curx = q.front().first.first;
        int cury = q.front().first.second;
        int curn = q.front().second;
        q.pop();
        if(visit[curx][cury] == 1){
            continue;
        }
        dist[curn].push_back({curx, cury});
        visit[curx][cury] = 1;
        for(int i = 0;i < 4;i++){
            int nxtx = curx+dx[i];
            int nxty = cury+dy[i];
            if(nxtx < 0 || nxtx >= r || nxty < 0 || nxty >= c){
                continue;
            }
            else if(visit[nxtx][nxty] == 1 || arr[nxtx][nxty] != 'X'){
                continue;
            }
            q.push({{nxtx, nxty}, curn+1});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> r >> c;
    for(int i = 0;i < r;i++){
        string temp;
        cin >> temp;
        for(int j = 0;j < c;j++){
            arr[i][j] = temp[j];
            if(temp[j] == 'L'){
                swan.push_back({i, j});
            }
        }
    }
    for(int i = 0;i < 1505;i++){
        for(int j = 0;j < 1505;j++){
            mm[i][j] = {i, j};
        }
    }
    init();
    bfs();
    /*
    for(int i = 1;i <= 5;i++){
        cout << i << endl;
        for(int j = 0;j < dist[i].size();j++){
            cout << dist[i][j].first << " " << dist[i][j].second << "\n";
        }
        cout << endl;
    }
    */
    int s1x = swan[0].first;
    int s1y = swan[0].second;
    int s2x = swan[1].first;
    int s2y = swan[1].second;
    int turn = 0;
    while(1){
        //cout << "inf";
        /*
        cout << turn << endl;
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                cout << arr[i][j];
            }
            cout << endl;
        }
        for(int i = 0;i < r;i++){
            for(int j = 0;j < c;j++){
                cout << mm[i][j].first << " " << mm[i][j].second << " / ";
            }
            cout << endl;
        }
        cout << endl;
        */
        if(srch(s1x, s1y) == srch(s2x, s2y)){
            cout << turn;
            break;
        }
        turn++;
        for(int i = 0;i < dist[turn].size();i++){
            int x = dist[turn][i].first;
            int y = dist[turn][i].second;
            arr[x][y] = '.';
        }
        for(int i = 0;i < dist[turn].size();i++){
            int x = dist[turn][i].first;
            int y = dist[turn][i].second;
            for(int j = 0;j < 4;j++){
                int xx = x + dx[j];
                int yy = y + dy[j];
                if(xx < 0 || xx >= r || yy < 0 || yy >= c){
                    continue;
                }
                if(arr[xx][yy] != 'X'){
                    comb(x, y, xx, yy);
                }
            }
        }
    }
}
