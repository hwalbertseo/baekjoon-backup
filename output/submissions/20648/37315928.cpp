#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int sy[2505];
int sx[2505];
map<int, int> m;
map<int, int> coo;
int board[2505][2505];

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        sy[i] = q;
        sx[i] = p;
        m[p] = q;
    }
    sort(sy, sy+n);
    for(int i = 0;i < n;i++){
        int idx = lower_bound(&sy[0], &sy[n], m[sx[i]]) - &sy[0];
        board[i+1][idx+1] = 1;
        coo[i+1] = idx+1;
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            board[i][j] = board[i][j] + board[i-1][j] + board[i][j-1] -board[i-1][j-1];
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            int maxy, miny;
            if(coo[i] > coo[j]){
                maxy = coo[i];
                miny = coo[j];
            }
            else{
                maxy = coo[j];
                miny = coo[i];
            }
            int upcnt = board[j][n] - board[j][maxy-1] - board[i-1][n] + board[i-1][maxy-1];
            int downcnt = board[j][miny] - board[i-1][miny] - board[j][0] + board[i-1][0];

            /*
            cout << "\n";
            cout << i << " "  << j <<"\n";
            cout << maxy << " "  << miny <<"\n";
            cout << upcnt << " " << downcnt << "\n";
            */
            cnt += upcnt*downcnt;
        }
    }

    cout << cnt+1;
}
