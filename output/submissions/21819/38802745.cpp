#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[100005];
ll dif[100005];
ll n, k, l;

ll solve(ll mid){
    ll idx = 0;
    ll now = dif[idx];
    ll cnt = 0;
    //cout << "\n" << mid << "\n";
    for(ll i = n-1;i >= 0;i--){
        //cout << arr[i] << " " << now << " ";
        if(arr[i] >= mid){
            cnt++;
            continue;
        }
        if(cnt >= mid){
            return 1;
        }
        if(idx >= l){
            return -1;
        }
        ll difference = mid - arr[i];
        //cout << difference << "\n";
        if(now >= difference){
            now -= difference;
            cnt++;
        }
        else if(dif[idx+1] >= difference){
            idx++;
            now = dif[idx];
            now -= difference;
            cnt++;
        }
        else{
            return -1;
        }
        if(now <= 0){
            idx++;
            now = dif[idx];
        }
        if(cnt >= mid){
            return 1;
        }
    }
    //cout << endl;
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
