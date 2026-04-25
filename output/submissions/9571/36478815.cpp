#include <iostream>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}


pair<ll, ll> arr[50005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, d;
    cin >> n >> d;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p, q};
    }
    sort(arr, arr+n, comp);
    set<ll> s;
    ll j = 0;
    ll cnt = 0;
    for(ll i = 0;i < n;i++){
        for(;arr[j].second >= arr[i].second*2;j++){
            s.insert(arr[j].first);
        }
        if(s.empty() || s.size() == 1){
            continue;
        }
        else{
            //s.insert(arr[i].first);
            auto lower = s.lower_bound(arr[i].first);
            auto higher = s.upper_bound(arr[i].first);
            if(lower == s.end() || higher == s.end()){
                continue;
            }
            if(*(lower--) >= arr[i].first - d && *higher <= arr[i].first + d){
                cnt++;
            }
        }
    }
    cout << cnt;
}

/*
6 4
12 4
6 2
5 3
9 7
3 6
11 2
*/
