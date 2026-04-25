#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

ll n, k, m;

ll def(ll mid){
    ll days = 0;
    ll paid = 0;
    bool passed = false;
    while(days <= k){
        if((n-paid) <= mid*m){
            //cout << "passed\n";
            passed = true;
            break;
        }
        ll y = (n-paid)/mid;
        ll temp = mid*y;
        ll now = (n-paid)-temp;
        ll cnt = now/y;
        cnt++;
        //cout << mid << " " << y << " " << days << " " << (n-paid) << " " << cnt << "\n";
        paid += (y*cnt);
        days += cnt;
    }
    if(passed){
        return (days + ((n-paid)/m) + 1);
    }
    return days;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("loan.in", "r", stdin);
    //freopen("loan.out", "w", stdout);
    cin >> n >> k >> m;
    ll lo = 1;
    ll hi = n;
    while(lo < hi){
        ll mid = (lo + hi)/2 + 1;
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
//1000000000000 1000000000000 1
