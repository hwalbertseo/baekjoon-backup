#include <iostream>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

ll ans[100005];
pair<ll,ll> arr[100005];
set<ll> s;

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll p;
        cin >> p;
        arr[i] = {p, i+1};
    }
    sort(arr, arr+n, comp);
    s.insert(0);
    s.insert(n+1);
    for(ll i = 0;i < n;i++){
        ll idx = arr[i].second;
        auto t = s.lower_bound(idx);
        auto b = t;
        b--;
        ll top;
        ll bot;
        if(*t == n+1){
            top = n;
        }
        else{
            ll temp = *t+idx;
            top = (temp)/2 - 1 + (temp%2);
        }
        ans[top+1]--;
        if(*b == 0){
            bot = 1;
        }
        else{
            ll temp = *b+idx;
            bot = (temp)/2 + 1;
        }
        ans[bot]++;
        //cout << arr[i].first << " " << bot << " " << top << endl;
        s.insert(idx);
    }
    for(ll i = 1;i <= n;i++){
        ans[i] = ans[i-1]+ans[i];
    }
    for(ll i = 1;i <= n;i++){
        cout << ans[i]-1 << " ";
    }
}
