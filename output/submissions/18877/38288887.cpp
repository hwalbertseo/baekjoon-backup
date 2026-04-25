#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m;
pair<ll, ll> arr[100005];

ll solve(ll mid){
    ll idx = 0;
    ll bef = 0;
    for(ll i = 1;i < n;i++){
        //cout << bef << " ";
        ll nxt = bef+mid;
        if(nxt > arr[m-1].second){
            return -1;
        }
        if(nxt <= arr[idx].second){
            bef = nxt;
        }
        else{
            idx++;
            i--;
            continue;
        }
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(ll i = 0;i < m;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p, q};
    }
    sort(arr, arr+m);
    ll hi = arr[m-1].second;
    ll lo = 1;
    while(lo < hi){
        ll mid = (hi+lo)/2 + 1;
        ll now = solve(mid);
        if(now == 1){
            lo = mid;
        }
        else{
            hi = mid-1;
        }
    }
    cout << hi;
}
