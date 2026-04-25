#include <iostream>

using namespace std;

int arr[2005][2005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j <= n;j++){
            arr[j][i] = arr[j][i] + arr[j-1][i];
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            arr[i][j] = arr[i][j] + arr[i-1][j-1];
        }
    }
/*
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
*/
    for(int i = 0;i < q;i++){
        int w, p;
        cin >> w >> p;
        cout << arr[w][p] << "\n";
    }
}