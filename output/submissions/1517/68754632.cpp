#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

pair<ll, ll> input[500005];
ll segtree[2000005];
ll m = 1;

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first < b.first;
}

void update(ll val, ll idx){
    idx += m-1;
    segtree[idx] = val;
    for(ll i = idx/2;i >= 1;i /= 2){
        segtree[i] = segtree[i*2] + segtree[i*2 + 1];
    }
}

ll srch(ll L, ll R, ll curnode, ll curL, ll curR){
    if(curL > R || curR < L){
        return 0;
    }
    else if(curL >= L && curR <= R){
        return segtree[curnode];
    }
    else{
        ll mid = curL + curR;
        mid /= 2;
        return srch(L, R, curnode*2, curL, mid) + srch(L, R, curnode*2+1, mid+1, curR);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    while(m < n) m <<= 2;
    for(ll i = 1;i <= n;i++){
        ll p; pair<ll, ll> q;
        cin >> p;
        q.first = p; q.second = i;
        input[i] = q;
    }
    sort(input+1, input+n+1, comp);
    ll ans = 0;
    for(ll i = 1;i <= n;i++){
        ll idx = input[i].second;
        update(1, idx);
        ans += srch(idx+m, m+n-1, 1, m, m*2-1);
        /*
        for(ll i = 1;i < m*2;i++){
            cout << segtree[i] << " ";
        }
        cout << "\n";
        */
    }

    

    cout << ans;
}