#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll child = 1;
pair<ll, ll> segtree[400000];

pair<ll, ll> srch(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    if(nodeL > R || nodeR < L){
        return {2e9, 0};
    }
    else if(L <= nodeL && nodeR <= R){
        return segtree[curnode];
    }
    else{
        ll mid = (nodeL + nodeR)/2;
        pair<ll, ll> p = srch(L, R, curnode*2, nodeL, mid);
        pair<ll ,ll> q = srch(L, R, curnode*2+1, mid+1, nodeR);
        if(p.first > q.first){
            return q;
        }
        else{
            return p;
        }
    }
}

ll binsrch(ll L, ll R){
    if(R - L < 0){
        return 0;
    }
    pair<ll, ll> p = srch(L, R, 1, child, child*2-1);
    ll m = p.first;
    ll idx = p.second;
    ll area = (R-L+1) * m;
    if(R-L == 0){
        return area;
    }
    else{
        return max(max(binsrch(L, idx+child-1), binsrch(idx+child+1, R)), area);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    while(child < n) child <<= 1;
    for(ll i = 0;i < n;i++){
        ll p;
        cin >> p;
        segtree[i+child] = {p, i};

    }
    for(ll i = child-1;i > 0;i--){
        pair<ll, ll> p = segtree[i*2];
        pair<ll, ll> q = segtree[i*2+1];
        if(p.first>q.first){
            segtree[i] = {q.first,q.second};
        }
        else{
            segtree[i] = {p.first, p.second};
        }
    }
    /*
    for(ll i = 1;i < child*2;i++){
        cout << segtree[i].first << " ";
    }
    cout << "\n";
    for(ll i = 1;i < child*2;i++){
        cout << segtree[i].second << " ";
    }
    cout << "\n";
    cout << "\n";*/
    ll ans = binsrch(child, child+n-1);
    cout << ans;
}