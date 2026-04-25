#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

priority_queue<ll, vector<ll>> pq;
pair<ll, ll> arr[500000];
priority_queue<ll, vector<ll>> pqp;

bool comp1(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

bool comp2(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    for(ll i = 0;i < n;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr+n, comp1);
    ll val = 0;
    for(ll j = 0;j < k;j++){
        ll rk;
        cin >> rk;
        pqp.push(rk);
    }
    //cout << "sorte";
    
    ll fst = 0;
    for(ll i = 0;i < k;i++){
        pair<ll, ll> p;
        p.first = pqp.top();
        pqp.pop();
        p.second = 2e9;
        ll idx = lower_bound(arr, arr+n, p) - arr;
        //cout << idx;
        /*
        for(ll j = 0;j < idx;j++){
            cout << arr[j].first << " " << arr[j].second << "\n";
        }
        */
        for(;fst < idx;fst++){
            pq.push(arr[fst].second);
        }
        if(!pq.empty()){
            val += pq.top();
            pq.pop();
        }
    }
    cout << val;
    
}