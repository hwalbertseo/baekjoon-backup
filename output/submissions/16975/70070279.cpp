#include <iostream>
#define ll long long

using namespace std;

ll segtree[400005];
ll treen = 1;

void build(){
    for(ll i = treen-1;i > 0;i--){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}

void update(ll r){
    for(ll i = r/2;i > 0;i /= 2){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}

void updatetree(ll beg, ll fin, ll r){
    beg += treen-1;
    fin += treen-1;
    segtree[beg] += r;
    update(beg);
    segtree[fin+1] -= r;
    if(fin+1 < 2*treen){
        update(fin+1);
    }
}

ll srch(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    if(L <= nodeL && nodeR <= R){
        return segtree[curnode];
    }
    else if(L > nodeR || R < nodeL){
        return 0;
    }
    else{
        ll mid = nodeL+nodeR; mid /= 2;
        return srch(L, R, curnode*2, nodeL, mid) + srch(L, R, curnode*2+1, mid+1, nodeR);
    }
}

void prlltree(){
    for(ll i = 1;i < treen*2;i++){
        cout << segtree[i] << " ";
    }
    cout <<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    while(treen < n) treen <<= 1;
    ll val = 0;
    for(ll i = 0;i < n;i++){
        ll p;
        cin >> p;
        segtree[treen+i] = p - val;
        val = p;
    }
    //prlltree();
    build();
    //prlltree();
    ll q;
    cin >> q;
    for(ll i = 0;i < q;i++){
        ll a;
        cin >> a;
        if(a == 1){
            ll b, c, d;
            cin >> b >> c >> d;
            updatetree(b, c, d);
        }
        else{
            ll b;
            cin >> b;
            cout << srch(treen, treen+b-1, 1, treen, treen*2-1) << "\n"; 
        }
        //prlltree();
    }
}