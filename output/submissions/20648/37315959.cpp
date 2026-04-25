#include <iostream>
#include <algorithm>
#include <map>
#define ll long long

using namespace std;

ll sy[2505];
ll sx[2505];
map<ll, ll> m;
map<ll, ll> coo;
int board[2505][2505];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        sy[i] = q;
        sx[i] = p;
        m[p] = q;
    }
    sort(sx, sx+n);
    sort(sy, sy+n);
    for(ll i = 0;i < n;i++){
        ll idx = lower_bound(&sy[0], &sy[n], m[sx[i]]) - &sy[0];
        board[i+1][idx+1] = 1;
        coo[i+1] = idx+1;
    }
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= n;j++){
            board[i][j] = board[i][j] + board[i-1][j] + board[i][j-1] -board[i-1][j-1];
        }
    }
    ll cnt = 0;
    for(ll i = 1;i <= n;i++){
        for(ll j = i;j <= n;j++){
            ll maxy, miny;
            if(coo[i] > coo[j]){
                maxy = coo[i];
                miny = coo[j];
            }
            else{
                maxy = coo[j];
                miny = coo[i];
            }
            ll upcnt = board[j][n] - board[j][maxy-1] - board[i-1][n] + board[i-1][maxy-1];
            ll downcnt = board[j][miny] - board[i-1][miny] - board[j][0] + board[i-1][0];

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
