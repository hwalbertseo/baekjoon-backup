#include <iostream>
#define ll long long

using namespace std;

ll h[505][505];
ll sm[505][505];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= n;j++){
            ll p;
            cin >> p;
            if(p < 100){
                sm[i][j] = 1;
            }
            if(p == 100){
                h[i][j] = 1;
            }
        }
    }
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= n;j++){
            sm[i][j] = sm[i][j] + sm[i-1][j] + sm[i][j-1] - sm[i-1][j-1];
            h[i][j] = h[i][j] + h[i-1][j] + h[i][j-1] - h[i-1][j-1];
        }
    }
    ll cnt = 0;
    for(ll i = 1;i <= n;i++){
        for(ll j = i;j <= n;j++){
            ll beg = 0;
            ll before = 0;
            for(ll k = 1;k <= n;k++){
                ll psm = sm[k][j] - sm[k][i-1] - sm[k-1][j] + sm[k-1][i-1];
                ll ph = h[k][j] - h[k][i-1] - h[k-1][j] + h[k-1][i-1];
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
