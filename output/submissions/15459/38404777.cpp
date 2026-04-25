#include <iostream>
#include <set>
#define ll long long

using namespace std;

pair<ll, ll> arr[100005];
multiset<ll> s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p, q};
    }
    ll tot = 0;
    ll ma = 2e9;
    ll j = 0;
    for(ll i = 0;i < n;i++){
        while(tot < m){
            s.insert(arr[j].second);
            tot += arr[j].first;
            j++;
        }
        auto it = s.end();
        it--;
        if(*it < ma){
            ma = *it;
        }
        s.erase(s.find(arr[i].second));
        tot -= arr[i].first;
    }
    cout << ma;
}
