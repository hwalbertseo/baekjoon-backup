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
        ll y = (n-paid)/mid;
        if(y <= m){
            passed = true;
            break;
        }
        //cout << 1 << endl;
        ll temp = mid*y;
        //cout << 2 << endl;
        ll now = (n-paid)-temp;
        //cout << 3 << " " << now << " " << y << endl;
        ll cnt = now/y;
        //cout << 4 << endl;
        cnt++;
        //cout << mid << " " << y << " " << days << " " << (n-paid) << " " << cnt << "\n";
        paid += (y*cnt);
        days += cnt;
    }
    if(passed){
        if((n-paid) % m != 0) return (days + ((n-paid)/m) + 1);
        else return (days + ((n-paid)/m));
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
