#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll l, n, m;
ll arr[50005];

bool solve(ll mid){
    ll cnt = 0;
    ll beg = 0;
    ll fin = -1;
    for(ll i = 1;i <= n+1;i++){
        fin = arr[i];
        if(fin - beg < mid){
            if(fin == l){
                if(cnt < m){
                    return true;
                }
                else{
                    return false;
                }
            }
            cnt++;
            continue;
        }
        else{
            beg = arr[i];
            continue;
        }
        //cout << "a: " << arr[i] << " " << arr[i-1] << "\n";
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
/*
24 7 4
3
6
9
12
15
18
21

21 6 3
3
6
9
12
15
18
*/
