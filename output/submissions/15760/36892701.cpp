#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#define ll long long

using namespace std;

ll arr[100005];
ll original[100005];
ll n;
map<ll, set<ll>> index;

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
        index[arr[i]].insert(i);
    }
    ll m = -1;
    for(ll i = 0;i < n;i++){
        ll idx = i - *index[original[i]].begin();
        index[original[i]].erase(index[original[i]].begin());
        if(idx < 0){
            continue;
        }
        if(idx > m){
            m = idx;
        }
    }
    cout << m+1;
}
