#include <iostream>
#include <algorithm>
#include <map>
#define ll long long

using namespace std;

ll arr[100005];
ll original[100005];
ll n;
map<ll, ll> index;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0;i < n;i++){
        ll p;
        cin >> p;
        arr[i] = p;
        original[i] = p;
    }
    sort(arr, arr+n);
    for(ll i = 0;i < n;i++){
        index[arr[i]] = i;
    }
    ll m = -1;
    for(ll i = 0;i < n;i++){
        ll idx = abs(i - index[original[i]]);
        if(idx > m){
            m = idx;
        }
    }
    cout << m+1;
}
