#include <iostream>

using namespace std;

int arr[2005][2005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
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
        int ans = 0;
        for(int j = p;j > 0;j--){
            if(w < 1){
                break;
            }
            ans += arr[w][j];
            w -= 1;
        }
        cout << ans << "\n";
    }
}