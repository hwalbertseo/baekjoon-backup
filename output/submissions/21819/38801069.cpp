#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[100005];
ll dif[100005];
ll n, k, l;

ll solve(ll mid){
    ll it = upper_bound(&arr[0], &arr[n], mid) - &arr[0] - 1;
    ll idx = 0;
    ll now = dif[idx];
    ll cnt = n-it-1;
    //cout << "mid: " << mid << " " << cnt << " " << it << "\n";
    while(cnt < mid){
        //cout << it << " " << arr[it] << "\n";
        if(idx >= l){
            return -1;
        }
        ll difference = mid - arr[it];
        if(now >= difference){
            now -= difference;
            it--;
            cnt++;
        }
        else if(dif[idx+1] >= difference){
            idx++;
            now = dif[idx];
            now -= difference;
            it--;
            cnt++;
        }
        else{
            return -1;
        }
        if(now <= 0){
            idx++;
            now = dif[idx];
        }
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
    for(ll i = 0;i < l;i++){
        dif[i] = k;
    }
    sort(arr, arr+n);
    ll hi = min(arr[n-1], n-1);
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
