#include <iostream>

using namespace std;

int table[1025][1025] = {0};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int temp;
            cin >> temp;
            table[i][j] = temp + table[i][j-1] + table[i-1][j] - table[i-1][j-1];
        }
    }
    for(int i = 0;i < m;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << table[y2][x2] - table[y2][x1-1] - table[y1-1][x2] + table[y1-1][x1-1] << "\n";
    }
}
