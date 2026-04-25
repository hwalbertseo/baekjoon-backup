#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

vector<ll> v;
vector<ll> v2;
int arr[45];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 0;i < n;i++){
        cin >> arr[i];
    }
    v.push_back(0);
    for(ll i = 0;i < n/2+1;i++){
        ll e = v.size();
        for(ll j = 0;j < e;j++){
            ll now = v[j] + arr[i];
            v.push_back(now);
        }
    }
    v2.push_back(0);
    sort(v.begin(), v.end());
    ll cnt = 0;
    for(ll i = n/2+1;i < n;i++){
        ll e = v2.size();
        for(ll j = 0;j < e;j++){
            //cout << j << "\n";
            ll now = v2[j]+arr[i];
            //cout << "re: " << lb << "\n";
            v2.push_back(now);
        }
    }
    for(ll i = 0;i < v2.size();i++){
        ll now = v2[i];
        ll fi = m-now;
        ll lb = lower_bound(v.begin(), v.end(), fi) - v.begin();
        if(v[lb] + now == m){
            ll ub = upper_bound(v.begin(), v.end(), fi) - v.begin();
            cnt += ub-lb;
            //cout << ub << " " << lb << "\n";
        }
    }
    if(m == 0){
        cnt--;
    }
    cout << cnt;
}
