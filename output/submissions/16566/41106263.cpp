#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll mm[4000005];
vector<ll> arr;

ll srch(ll a){
    //cout << "in";
    if(mm[a] == a){
        return a;
    }
    return mm[a] = srch(mm[a]);
}

int main()
{
    //ios_base::sync_with_stdio(false); cin.tie(0);
    for(ll i = 0;i < 4000005;i++){
        mm[i] = i;
    }
    ll n, m, k;
    cin >> n >> m >> k;
    for(ll i = 0;i < m;i++){
        ll p;
        cin >> p;
        arr.push_back(p);
    }
    sort(arr.begin(), arr.end());
    for(ll j = 0;j < k;j++){
        //cout << "in";
        ll p;
        cin >> p;
        auto it = upper_bound(arr.begin(), arr.end(), p);
        ll idx = it - arr.begin();
        ll cur = srch(*it);
        cout << srch(*it) << "\n";
        mm[cur] = srch(arr[idx+1]);
    }
    /*
    for(int i = 0;i < n;i++){
        cout << mm[i] << " ";
    }
    */
}
