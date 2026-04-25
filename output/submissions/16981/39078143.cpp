#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

pair<ll, ll> arr[100005];
ll fr[100005];

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p,q};
    }
    sort(arr, arr+n, comp);
    for(ll i = 0;i < m;i++){
        cin >> fr[i];
    }
    sort(fr, fr+m);
    ll idx = m-1;
    ll ans = 0;
    for(ll i = n-1;i >= 0;i--){
        if(arr[i].first <= fr[idx]){
            ans++;
            idx--;
        }
    }
    cout << ans;
}
