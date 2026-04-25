#include <iostream>
#include <set>
#define ll long long

using namespace std;

set<ll> s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    for(int i = 0;i < m;i++){
        ll p;
        cin >> p;
        s.insert(p);
    }
    for(int  j = 0;j < k;j++){
        ll p;
        cin >> p;
        auto it = s.upper_bound(p);
        cout << (*it) << "\n";
        s.erase(it);
    }
}
