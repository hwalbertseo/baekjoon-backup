#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[300005];
ll ans[300005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll mindex = 2e10;
    for(ll i = 1;i <= n;i++){
        ll p;
        cin >> p;
        if(p > mindex){
            arr[i] = mindex;
        }
        else{
            arr[i] = p;
            mindex = p;
        }
    }
    ll idx = n;
    ll a = 1;
    ll rec = 0;
    for(ll i = 1;i <= m;i++){
        cin >> ans[i];
    }
    while(idx >= 1 && a <= m){
        if(ans[a] <= arr[idx]){
            rec = idx;
            a++;
        }
        idx--;
    }
    if(n < m){
        rec = 0;
    }
    cout << rec;
}
