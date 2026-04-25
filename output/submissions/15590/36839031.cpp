#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

ll cow[100005];
ll farmer[100005];
vector<pair<ll, ll>> market;
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
    /*
    for(ll i = 1;i <= n;i++){
        cow[i] = cow[i-1] + cow[i];
    }
    */
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

    ll maxprice = -1;

    for(ll i = 1;i <= n;i++){
        if(market.empty()){
            break;
        }
        while(cow[i] > 0){
            if(market.empty()){
                break;
            }
            if(cow[i] < market[0].first){
                marketprice[i] += market[0].second * cow[i];
                market[0].first -= cow[i];
                cow[i] = 0;
            }
            else if(cow[i] == market[0].first){
                marketprice[i] += market[0].second * cow[i];
                market.erase(market.begin());
                cow[i] = 0;
            }
            else{
                marketprice[i] += market[0].second * market[0].first;
                cow[i] -= market[0].first;
                market.erase(market.begin());
            }
        }
        marketprice[i] += marketprice[i-1];

        ll price = marketprice[i] + farmerprice[i];
        if(price > maxprice){
            maxprice = price;
        }
        else{
            break;
        }

    }
    cout << maxprice;

}
