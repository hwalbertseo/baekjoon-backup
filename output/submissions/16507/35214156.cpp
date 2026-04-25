#include <iostream>

using namespace std;

int table[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int x, y, num;
    cin >> x >> y >> num;
    for(int i = 1;i <= x;i++){
        for(int j = 1;j <= y;j++){
            int temp;
            cin >> temp;
            table[i][j] = temp + table[i-1][j] + table[i][j-1] - table[i-1][j-1];
        }
    }

    for(int i = 0;i < num;i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int temp = table[x2][y2] - table[x1-1][y2] - table[x2][y1-1] + table[x1-1][y1-1];
        temp = temp/((x2-x1 + 1)*(y2-y1+1));
        cout << temp << "\n";
    }
}
