#include <iostream>
#define ll long long

using namespace std;

ll n, k, m;

ll def(ll mid){
    ll days = 0;
    ll paid = 0;
    bool passed = false;
    while(days <= k && paid < n){
        if((n-paid) <= mid*m){
            passed = true;
            break;
        }
        days++;
        ll y = (n-paid)/mid;
        if(y < m){
            y = m;
        }
        paid += y;
    }
    if(passed){
        return (days + ((n-paid)/m) + 1);
    }
    return days;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k >> m;
    ll lo = 1;
    ll hi = n;
    while(lo < hi){
        ll mid = (lo + hi)/2;
        ll days = def(mid);
        //cout << mid << " " << days << "\n";
        if(days > k){
            hi = mid-1;
            continue;
        }
        else{
            lo = mid;
            continue;
        }
    }
    cout << lo;
}
