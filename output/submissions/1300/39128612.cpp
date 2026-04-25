#include <iostream>
#define ll long long

using namespace std;

ll n, k;

ll solve(ll mid){
    ll ans = 0;
    for(ll i = 1;i <= n;i++){
        ll now = mid/i;
        if(now == 0){
            break;
        }
        else if(now > n){
            ans += n;
        }
        else{
            ans += now;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    ll hi = (n*n < 1e9) ? n*n : 1e9;
    ll lo = 1;
    while(lo < hi){
        ll mid = (hi+lo)/2;
        ll ans = solve(mid);
        //cout << mid << " " << ans << "\n";
        if(ans < k){
            lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    cout << lo;
}
