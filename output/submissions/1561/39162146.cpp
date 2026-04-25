#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

ll n, m;
ll arr[31];
vector<ll> v;
vector<ll> cart[31];
vector<ll> cnt;

ll solve(ll mid){
    ll ans = m;
    for(ll i = 0;i < v.size();i++){
        ans += (mid/v[i])*arr[v[i]];
    }
    //cout << mid << " " << ans << "\n";
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(ll i = 0;i < m;i++){
        ll p;
        cin >> p;
        arr[p]++;
        cart[p].push_back(i+1);
    }

    for(ll i =0;i < 30;i++){
        if(arr[i] > 0)
            v.push_back(i);
    }
    ll hi = 6e10;
    ll lo = 0;
    while(lo < hi){
        ll mid = (hi+lo)/2;
        ll ans = solve(mid);
        if(ans >= n){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    if(lo == 0){
        cout << n;
    }
    else{
        ll ans = solve(lo-1);
        ans = n-ans;
        for(ll i = 1;i < 31;i++){
            if(lo%i == 0){
                for(ll j = 0;j < cart[i].size();j++){
                    cnt.push_back(cart[i][j]);
                }
            }
        }
        sort(cnt.begin(), cnt.end());
        cout << cnt[ans-1];
    }
    /*
10 5
7 8 9 7 8
    */

}
