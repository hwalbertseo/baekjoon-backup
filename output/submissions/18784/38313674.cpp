#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#define ll long long

using namespace std;

vector<ll> x[100005];
vector<ll> y[100005];
pair<ll, ll> arr[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("triangles.in", "r", stdin);
    //freopen("triangles.out", "w", stdout);
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        p += 10000;
        q += 10000;
        x[p].push_back(q);
        y[q].push_back(p);
        arr[i] = {p,q};
    }
    for(ll i = 0;i < n;i++){
        ll xx = arr[i].first;
        ll yy = arr[i].second;
        if(x[xx].size() > 1 && y[yy].size() > 1){
            ll xsum = 0;
            ll ysum = 0;
            for(ll j = 0;j < x[xx].size();j++){
                xsum += abs(x[xx][j] - xx);
            }
            for(ll j = 0;j < y[yy].size();j++){
                ysum += abs(y[yy][j] - yy);
            }
            ans += xsum*ysum;
            ans %= 1000000007;
            //cout << xsum << "/" << ysum << endl;
        }
    }
    cout << ans;
}
/*
9
-2 1
1 3
1 2
1 1
1 0
1 -1
1 -2
2 1
3 1
*/
