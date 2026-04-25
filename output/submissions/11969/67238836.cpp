#include <iostream>

using namespace std;

int arr[3][1000000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        arr[temp-1][i+1]++;
    }
    for(int i = 1;i < n+1;i++){
        for(int j = 0;j < 3;j++){
            arr[j][i] = arr[j][i-1] + arr[j][i];
        }
    }
/*
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < n+1;j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
*/
    for(int i = 0;i < q;i++){
        int a, b;
        cin >> a >> b;
        cout << arr[0][b] - arr[0][a-1] << " ";
        cout << arr[1][b] - arr[1][a-1] << " ";
        cout << arr[2][b] - arr[2][a-1] << " ";
        cout << "\n";
    }
}