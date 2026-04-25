#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

pair<ll, ll> segtree[400005];
ll daugh = 1;

void reset(){
    //cout << "resetting\n";
    for(int i = 0;i < 400005;i++){
        segtree[i] = {0, 0};
    }
    for(ll i = daugh;i < daugh*2;i++){
        segtree[i] = {i-daugh, i-daugh};
    }
    for(ll i = daugh-1;i > 0;i--){
        segtree[i].first = min(segtree[i*2].first, segtree[i*2+1].first);
        segtree[i].second = max(segtree[i*2].second, segtree[i*2+1].second);
    }
    //cout << "reset\n";
}

void update(ll idx, ll val){
    idx += daugh;
    segtree[idx].first = val;
    segtree[idx].second = val;
    //cout << idx << " " << segtree[idx].first << " " << val << "\n";
    for(ll i = idx/2;i > 0;i /= 2){
        segtree[i].first = min(segtree[i*2].first, segtree[i*2+1].first);
        segtree[i].second = max(segtree[i*2].second, segtree[i*2+1].second);
    }
    //cout << idx << " " << segtree[idx].first << " " << val << "\n";
}

ll srchMin(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    if(nodeL > R || nodeR < L){
        return (ll)2e9;
    }
    else if(nodeL >= L && nodeR <= R){
        return segtree[curnode].first;
    }
    else{
        ll mid = (nodeL + nodeR)/2;
        return min(srchMin(L, R, curnode*2, nodeL, mid), srchMin(L, R, curnode*2+1, mid+1, nodeR));
    }
}

ll srchMax(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    if(nodeL > R || nodeR < L){
        return -1;
    }
    else if(nodeL >= L && nodeR <= R){
        return segtree[curnode].second;
    }
    else{
        ll mid = (nodeL + nodeR)/2;
        return max(srchMax(L, R, curnode*2, nodeL, mid), srchMax(L, R, curnode*2+1, mid+1, nodeR));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t;
    cin >> t;
    for(int tt = 0;tt < t;tt++){
        //cout << tt << "\n";
        daugh = 1;
        ll n, k;
        cin >> n >> k;
        while(daugh < n) daugh <<= 1;
        reset();
        for(ll i = 0;i < k;i++){
            ll a, p, q;
            cin >> a >> p >> q;
            if(a == 0){
                ll val1 = segtree[p+daugh].first;
                ll val2 = segtree[q+daugh].first;
                //cout << val1 << " " << val2 << "\n";
                update(p, val2);
                update(q, val1);
            }
            else{  
                p += daugh;
                q += daugh;
                ll mi = srchMin(p, q, 1, daugh, daugh*2-1);
                ll ma = srchMax(p, q, 1, daugh, daugh*2-1);
                if(mi == p - daugh && ma == q - daugh){
                    cout << "YES\n";
                }
                else{
                    cout << "NO\n";
                }
                
            }
            /*
            for(ll i = 1;i <= daugh*2-1;i++){
                cout << segtree[i].first << " ";
            }
            cout << "\n";
            for(ll i = 1;i <= daugh*2-1;i++){
                cout << segtree[i].second << " ";
            }
            cout << "\n\n";
            */
        }
    }
}