#include <iostream>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

ll want[1005];
ll ans[1005];
set<pair<ll, ll>> s;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, d;
    cin >> n >> d;
    for(ll i = 0;i < n;i++){
        cin >> want[i];
    }
    for(int i = 0;i < n;i++){
        bool passed = true;
        ll befend = 0;
        ll w = want[i];
        ll least = -1;
        for(pair<ll, ll> temp: s){
            ll beg = temp.first;
            ll fin = temp.second;
            if(w >= beg && w <= fin){
                passed = false;
            }
            if(beg > befend+1){
                if(befend+1 >= want[i] && least == -1){
                    least = befend+1;
                }
            }
            befend = fin;
        }
        if(passed){
            ans[i] = want[i];
            ll dif = d-1;
            s.insert({want[i]-dif, want[i]+dif});
        }
        else{
            if(least != -1){
                ans[i] = least;
                ll dif = d-1;
                s.insert({ans[i]-dif, ans[i]+dif});
            }
            else{
                auto tp = s.end();
                tp--;
                ans[i] = (tp->second) + 1;
                ll dif = d-1;
                s.insert({ans[i]-dif, ans[i]+dif});
            }
        }
        cout << ans[i] << " ";
    }
}
