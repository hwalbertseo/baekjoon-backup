#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

int arr[505][505];
int been[505][505];
int n, m;

int coords[4][4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int dfs(int x, int y){
    //cout << x << " " << y << " " << arr[x][y] << "\n";
    if(x == n && y == m){
        return 1;
    }
    int total = 0;
    for(int i = 0;i < 4;i++){
        int cx = x + coords[i][0];
        int cy = y + coords[i][1];
        //cout << cx << " " << cy << " " << arr[cx][cy] << "\n";
        if(cx < 1 || cy < 1 || cx > n || cy > m){
            continue;
        }
        if(arr[cx][cy] < arr[x][y]){
            if(been[cx][cy] != 0){
                total += been[cx][cy];
            }
            else{
                int nxt = dfs(cx, cy);
                total += nxt;
            }
        }
    }
    been[x][y] = total;
    //cout << "\n";
    return total;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
        }
    }
    cout << dfs(1, 1);
}