#include <iostream>

using namespace std;

int r, c, t;
int cur[55][55];
int tc[2];
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void spread(){
    int state[55][55];
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            state[i][j] = cur[i][j];
        }
    }
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            if(state[i][j] <= 0){
                continue;
            }
            int sp = state[i][j]/5;
            for(int ii = 0;ii < 4;ii++){
                int xx = i+dx[ii];
                int yy = j+dy[ii];
                if(xx < 0 || xx >= r || yy < 0 || yy >= c){
                    continue;
                }
                if(cur[xx][yy] == -1){
                    continue;
                }
                cur[xx][yy] += sp;
                cur[i][j] -= sp;
            }
        }
    }
}

void clean(){
    // top part
    for(int i = tc[0]-1;i >= 0;i--){
        if(cur[i+1][0] != -1){
            cur[i+1][0] = cur[i][0];
            cur[i][0] = 0;
        }
    }
    for(int j = 1;j < c;j++){
        cur[0][j-1] = cur[0][j];
        cur[0][j] = 0;
    }
    for(int i = 1;i <= tc[0];i++){
        cur[i-1][c-1] = cur[i][c-1];
        cur[i][c-1] = 0;
    }
    for(int j = c-2;j >= 1;j--){
        cur[tc[0]][j+1] = cur[tc[0]][j];
        cur[tc[0]][j] = 0;
    }
    //bottom part
    for(int i = tc[1]+1;i < r;i++){
        if(cur[i-1][0] == -1){
            continue;
        }
        cur[i-1][0] = cur[i][0];
        cur[i][0] = 0;
    }
    for(int j = 1;j < c;j++){
        cur[r-1][j-1] = cur[r-1][j];
        cur[r-1][j] = 0;
    }
    for(int i = r-2;i >= tc[1];i--){
        cur[i+1][c-1] = cur[i][c-1];
        cur[i][c-1] = 0;
    }
    for(int j = c-2;j >= 1;j--){
        if(cur[tc[1]][j+1] == -1){
            cur[tc[1]][j] = 0;
            continue;
        }
        cur[tc[1]][j+1] = cur[tc[1]][j];
        cur[tc[1]][j] = 0;
    }

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> r >> c >> t;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            cin >> cur[i][j];
            if(cur[i][j] == -1){
                if(tc[0] == 0){
                    tc[0] = i;
                }
                else{
                    tc[1] = i;
                }
            }
        }
    }
    for(int i = 0;i < t;i++){
        spread();
        clean();
    }
    int ans = 0;
    for(int i = 0;i < r;i++){
        for(int j = 0;j < c;j++){
            if(cur[i][j] != -1){
                ans += cur[i][j];
            }
            //cout << cur[i][j] << " ";
        }
        //cout << endl;
    }
    cout << ans;
}
