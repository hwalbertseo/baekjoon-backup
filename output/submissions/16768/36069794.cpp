#include <iostream>

using namespace std;

int n, k;
int arr[105][15];
int sx1 = -1, sy1 = -1, sx2 = -1, sy2 = -1;
int mx[15];
int mn[15];
bool exist = false;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void init(){
    exist = false;
    for(int i = 0;i < 15;i++){
        mx[i] = -1;
        mn[i] = 0;
    }
}


void ff(int x, int y, int cur, int num){
    //cout <<x << " " << y << " " << cur << " " << num << "\n";
    if(num >= k){
        exist = true;
        arr[x][y] = 0;
        if(mx[y] < x) mx[y] = x;
        if(mn[y] > x) mn[y] = x;
        //cout << y << " " << mx[y] << " " << mn[y] << "\n";
    }
    else{
        if(sx1 == -1 && sy1 == -1){
            sx1 = x;
            sy1 = y;
        }
        else{
            sx2 = x;
            sy2 = y;
        }
    }
    for(int i = 0;i < 4;i++){
        int xx = dx[i] + x;
        int yy = dy[i] + y;
        if(xx < 0 || xx >= n || yy < 0 || yy >= 10){
            continue;
        }
        if(arr[xx][yy] == cur){
            //cout << "sx: " << sx1 << " " << sy1 << endl;
            if(xx == sx1 && yy == sy1 && num<k){
                continue;
            }
            if(xx == sx2 && yy == sy2 && num<k){
                continue;
            }
            ff(xx, yy, cur, num+1);
            if(num < k) break;
        }
    }
}

void gravity(int y){
    int dif = mx[y] - mn[y]+1;
    //cout << y << " " << mx[y] << " " << mn[y] << "\n";
    //if(mx[y] == -1 && mx[y] == mn[y]) return;
    if(dif <= 0) return;
    for(int i = mx[y]+1;arr[i][y] != 0;i++){
        //cout << mx[y] << " " << mn[y] << "\n";
        arr[i-dif][y] = arr[i][y];
        arr[i][y] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for(int i = n-1;i >= 0;i--){
        string temp;
        cin >> temp;
        for(int j = 0;j < 10;j++){
            arr[i][j] = temp[j]-48;
        }
    }
    while(1){
        init();
        for(int i = 0;i < n;i++){
            //int zcount = 0;
            for(int j = 0;j < 10;j++){
                if(arr[i][j] != 0) {
                    ff(i, j, arr[i][j], 1);
                    sx1 = -1;
                    sx2 = -1;
                    sy1 = -1;
                    sy2 = -1;
                }
            }
/*
            cout << "\n";
            for(int i = n-1;i >= 0;i--){
                for(int j = 0;j < 10;j++){
                    cout << arr[i][j];
                }
            cout << "\n";
            }
*/
            //if(zcount >= 10) break;
        }
        /*
        cout << "\n";
            for(int i = n-1;i >= 0;i--){
                for(int j = 0;j < 10;j++){
                    cout << arr[i][j];
                }
            cout << "\n";
            }
        */
        for(int i = 0;i < 10;i++){
            gravity(i);
        }
        if(!exist) break;
/*
        cout << "\n";
            for(int i = n-1;i >= 0;i--){
                for(int j = 0;j < 10;j++){
                    cout << arr[i][j];
                }
            cout << "\n";
            }
            */
    }
    cout << "\n";
    for(int i = n-1;i >= 0;i--){
        for(int j = 0;j < 10;j++){
            cout << arr[i][j];
        }
        cout << "\n";
    }
}
