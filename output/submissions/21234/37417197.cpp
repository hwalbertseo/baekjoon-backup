#include <iostream>

using namespace std;

int h[505][505];
int sm[505][505];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int p;
            cin >> p;
            if(p < 100){
                sm[i][j] = 1;
            }
            if(p == 100){
                h[i][j] = 1;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            sm[i][j] = sm[i][j] + sm[i-1][j] + sm[i][j-1] - sm[i-1][j-1];
            h[i][j] = h[i][j] + h[i-1][j] + h[i][j-1] - h[i-1][j-1];
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            int beg = 0;
            int before = 0;
            for(int k = 1;k <= n;k++){
                int psm = sm[k][j] - sm[k][i-1] - sm[k-1][j] + sm[k-1][i-1];
                int ph = h[k][j] - h[k][i-1] - h[k-1][j] + h[k-1][i-1];
                if(psm > 0){
                    beg=k;
                    before = 0;
                    continue;
                }
                else{
                    if(ph > 0){
                        cnt += k-beg;
                        before = k-beg;
                    }
                    else{
                        cnt += before;
                    }
                }
            }
            //cout << i << " " << j << " " <<cnt << endl;
        }
    }
    cout << cnt;
}
