#include <iostream>
#include <vector>
#define ll long long
#define pii pair<ll, ll>
#define pll pair<long long, long long>

using namespace std;

ll segtree[2000005];
pii ett[500005];
vector<ll> graph[500005];
ll treen = 1;
ll wage[500005];

ll sttind = 0;
void dfs(ll curnode){
    ett[curnode].first = ++sttind;
    if(graph[curnode].empty()){
        ett[curnode].second = sttind;
        return;
    }
    for(ll next : graph[curnode]){
        dfs(next);
    }
    ett[curnode].second = sttind;
}

void updatepoll(ll idx){
    for(ll i = idx/2;i > 0;i /= 2){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}

void updatetree(ll l, ll r, ll val){
    l += treen;
    r += treen;
    segtree[l] += val;
    updatepoll(l);
    segtree[r] -= val;
    if(r < treen*2){
        updatepoll(r);
    }
}

ll srch(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    if(L <= nodeL && nodeR <= R){
        return segtree[curnode];
    }
    else if(R < nodeL || nodeR < L){
        return 0;
    }
    else{
        ll mid = (nodeL+nodeR)/2;
        return srch(L, R, curnode*2, nodeL, mid) + srch(L, R, curnode*2+1, mid+1, nodeR);
    }
}

void prlltree(){
    for(ll i = 1;i < treen*2;i++){
        cout << segtree[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    while(treen < n) treen <<= 1;
    ll Mirko;
    cin >> Mirko;
    wage[1] = Mirko;
    for(ll i = 1;i < n;i++){
        ll q;
        cin >> wage[i+1] >> q;
        graph[q].push_back(i+1);
    }
    dfs(1);
    for(ll i = treen;i < treen+n;i++){
        segtree[ett[i-treen+1].first+treen-1] = wage[i-treen+1];
    }
    for(ll i = treen+n-1;i >= treen;i--){
        segtree[i] -= segtree[i-1];
    }
    for(ll i = treen-1;i > 0;i--){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
    //prlltree();
    for(ll i = 0;i < m;i++){
        char c; cin >> c;
        if(c == 'p'){
            ll head, val;
            cin >> head >> val;
            updatetree(ett[head].first, ett[head].second, val);
        }
        else{
            ll idx;
            cin >> idx;
            idx = ett[idx].first;
            cout << srch(treen, treen+idx-1, 1, treen, treen*2-1) << "\n";
        }
        //prlltree();
    }
}