#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

ll cow[100005];
ll farmer[100005];
vector<pair<ll, ll>> market;
vector<ll> pq, ppq;
ll marketprice[100005];
ll farmerprice[100005];

bool comp(ll a, ll b){
    return a > b;
}

bool comppair(pair<ll, ll> a, pair<ll, ll> b){
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, r;
    cin >> n >> m >> r;
    for(ll i = 1;i <= n;i++){
        ll p;
        cin >> p;
        cow[i] = p;
    }
    sort(cow+1, cow+n+1, comp);
    for(ll i = 1;i <= n;i++){
        cow[i] = cow[i-1] + cow[i];
    }
    for(ll i = 0;i < m;i++){
        ll p, q;
        cin >> p >> q;
        market.push_back({p, q});
    }

    for(ll i = 1;i <= r;i++){
        ll p;
        cin >> p;
        farmer[i] = p;
    }
    sort(farmer+1, farmer+r+1, comp);
    for(ll i = n-1;i >= 0;i--){
        farmerprice[i] = farmer[n-i] + farmerprice[i+1];
    }

    sort(market.begin(), market.end(), comppair);

    pq.push_back(market[0].first);
    ppq.push_back(market[0].first * market[0].second);
    for(int i = 0;i < m;i++){
        pq.push_back(pq[i] + market[i+1].first);
        ppq.push_back(ppq[i] + market[i+1].first * market[i+1].second);
    }

    ll maxprice = -1;

    for(ll i = 1;i <= n;i++){

        auto it = lower_bound(pq.begin(), pq.end(), cow[i]);
        ll idx = it-pq.begin();

        if(idx == 0){
            marketprice[i] = cow[i]*market[idx].second;
        }
        else{
            marketprice[i] = ppq[idx-1] + (cow[i]-pq[idx-1])*market[idx].second;
        }

        ll price = marketprice[i] + farmerprice[i];
        if(price >= maxprice){
            maxprice = price;
        }
        else{
            break;
        }

    }
    cout << maxprice;

}
