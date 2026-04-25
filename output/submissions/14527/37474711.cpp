#include <iostream>
#include <map>
#include <algorithm>
#define ll long long

using namespace std;

map<ll, ll> m;
ll arr[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    ll total = 0;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        m[q] = p;
        total += p;
        arr[i] = q;
    }
    sort(arr, arr+n);
    ll biggest = -1;
    ll smind = 0;
    for(ll i = n-1;i >= 0;i--){
        ll biind = arr[i];
        while(m[biind] > 0){
            ll realsmall = arr[smind];
            ll big = biind + realsmall;
            m[biind]--;
            m[smind]--;
            if(biggest < big){
                biggest = big;
            }
            if(m[realsmall] <= 0){
                smind++;
            }
        }
    }
    cout << biggest;
}
