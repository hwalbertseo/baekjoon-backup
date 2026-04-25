#include <iostream>

using namespace std;

char nonblind[105][105];
char blind[105][105];
int visit[105][105];
int colorblind = 0;
int notblind = 0;
int n;

void init(){
    for(int i = 0;i < 105;i++){
        for(int j = 0; j < 105;j++){
            visit[i][j] = 0;
        }
    }
}

void dfs(int x, int y, char srch, int b){
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    visit[x][y] = 1;
    for(int i = 0;i < 4;i++){
        int xx = x + dx[i];
        int yy = y + dy[i];

        if(xx < 0 || xx >= n || yy < 0 || yy >= n || visit[xx][yy] == 1){
            continue;
        }
        else if((b == 1) ? blind[xx][yy] == srch : nonblind[xx][yy] == srch){
            dfs(xx, yy, srch, b);
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0;i < n;i++){
        string temp;
        cin >> temp;
        for(int j = 0;j < n;j++){
            nonblind[i][j] = temp[j];
            if(temp[j] == 'G'){
                blind[i][j] = 'R';
            }
            else{
                blind[i][j] = temp[j];
            }
        }
    }
    init();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(visit[i][j] == 0){
                notblind++;
                dfs(i, j, nonblind[i][j], 0);
            }
        }
    }
    init();
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(visit[i][j] == 0){
                colorblind++;
                dfs(i, j, blind[i][j], 1);
            }
        }
    }
    cout << notblind << " " << colorblind;
}
