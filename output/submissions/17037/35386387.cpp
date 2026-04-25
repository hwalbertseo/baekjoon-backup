#include <iostream>

using namespace std;

int arr[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0;i < n;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[x1][y1]++;
        arr[x2][y2]++;
        arr[x1][y2]--;
        arr[x2][y1]--;
    }
    int cnt = 0;
    for(int i = 1;i < 1000;i++){
        for(int j = 1;j < 1000;j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + arr[i][j];
            if(arr[i][j] == k) cnt++;
        }
    }
    cout << cnt;
}
