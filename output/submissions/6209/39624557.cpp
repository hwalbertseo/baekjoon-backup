#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll l, n, m;
ll arr[50005];

bool solve(ll mid){
    ll cnt = 0;
    ll blow = -1;
    ll up = 0;
    for(ll i = 1;i <= n+1;i++){
        ll now = arr[i] - arr[i-1];
        //cout << "a: " << arr[i] << " " << arr[i-1] << "\n";
        if(now < mid){
            if(arr[i] == l){
                if(blow == arr[i-1]){
                    if(up%2 == 1){
                        return false;
                    }
                }
            }

            if(blow == arr[i-1]){
                if(up % 2 == 1){
                    cnt++;
                    //cout << "a: " << arr[i] << " " << arr[i-1] << "\n";
                }
                up++;
            }
            else{
                up = 0;
                cnt++;
                //cout << "a: " << arr[i] << " " << arr[i-1] << "\n";
            }
            blow = arr[i];
        }
    }
    //cout << mid << " " << cnt << "\n";
    if(cnt <= m){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    cin >> l >> n >> m;
    arr[0] = 0;
    for(ll i = 1;i <= n;i++){
        cin >> arr[i];
    }
    arr[n+1] = l;
    sort(arr, arr+n+2);
    ll hi = l;
    ll lo = 0;
    //cout << solve(4);

    while(lo < hi){
        ll mid = (hi+lo)/2 + 1;
        bool temp = solve(mid);
        //cout << mid << " " << temp << "\n";
        if(temp){
            lo = mid;
        }
        else{
            hi = mid-1;
        }
    }
    cout << lo;

}
