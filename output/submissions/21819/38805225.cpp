#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[100005];
ll dif[100005];
ll n, k, l;

ll solve(ll mid){
    ll cnt = 0;
    for(ll i = n-1;i >= n-mid;i--){
        dif[n-1-i] = max(mid - arr[i], (ll)0);
        if(arr[i] >= mid){
            cnt++;
        }
    }
    if(cnt >= mid){
        return 1;
    }
    ll times = 0;
    //cout << mid << endl;
    for(ll i = 0;i < mid;i++){
        //cout << dif[i] << " ";
        if(dif[i] > k){
            return -1;
        }
        if(dif[i] != 0){
            times += dif[i];
        }
    }
    //cout << times << "\n";
    if(times > l*k){
        return -1;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> l;
    for(ll i = 0;i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    ll hi = n;
    ll lo = 0;
    while(lo < hi){
        ll mid = (lo+hi)/2 + 1;
        ll temp = solve(mid);
        if(temp == -1){
            hi = mid-1;
        }
        else{
            lo = mid;
        }
    }
    cout << lo;
}
