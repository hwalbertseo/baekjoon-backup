#include <iostream>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

ll dif[65540];
set<pair<ll, ll>> s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        ll p;
        cin >> p;
        ll lo;
        ll hi;
        for(int j = 0;j < 12;j++){
            if((p-j) % 12 == 0){
                lo = p-j;
                break;
            }
        }
        hi = lo+12;
        s.insert({lo, hi});
    }
    s.insert({0, 0});
    auto bc = s.end();
    bc--;
    ll ans = (*bc).second;
    bc--;
    ll idx = 0;
    for(auto it = s.begin();it != bc;it++){
        auto next = it;
        next++;
        dif[idx] = (*next).first - (*it).second;
        idx++;
    }
    sort(dif, dif+idx, greater<ll>());
    for(ll i = 0;i < m-1;i++){
        ans -= dif[i];
    }
    cout << ans;
}
