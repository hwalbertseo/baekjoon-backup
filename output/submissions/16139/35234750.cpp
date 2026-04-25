#include <iostream>

using namespace std;

int arr[26][200005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string str;
    cin >> str;
    int m;
    cin >> m;
    for(int i = 1;i <= str.size();i++){
        arr[str[i-1]-96][i] += 1;
        for(int j = 0;j < 26;j++){
            arr[j][i] += arr[j][i-1];
        }
    }
    /*
    for(int i = 0;i < 26;i++){
        for(int j = 1;j <= str.size();j++){
            cout << arr[i+1][j] << " ";
        }
        cout << "\n";
    }
    */
    for(int i = 0;i<m;i++){
        char p;
        int l, r;
        cin >> p >> l >> r;
        cout << arr[p-96][r+1] - arr[p-96][l] << "\n";
    }
}
