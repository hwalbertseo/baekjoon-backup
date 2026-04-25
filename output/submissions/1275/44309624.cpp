#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m, leaf = 1;
ll tree[400005];

void construct(){
    for(ll i = leaf-1;i > 0;i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void update(ll place, ll num){
    place += leaf-1;
    tree[place] = num;
    for(ll i = place/2;i > 0;i /= 2){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

ll sum(ll L, ll R, ll cur, ll Lnode, ll Rnode){
    if(R<Lnode || L > Rnode){
        return 0;
    }
    else if(L <= Lnode && Rnode <= R){
        return tree[cur];
    }
    ll mid = (Lnode+Rnode)/2;
    return sum(L, R, cur*2, Lnode, mid) + sum(L, R, cur*2+1, mid+1, Rnode);
}

void printtree(){
    cout << "pt: ";
    for(ll i = 1;i <= leaf*2;i++){
        cout << tree[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while(leaf < n) (leaf <<= 1);
    //cout << leaf <<"\n";
    for(ll i = leaf;i < leaf+n;i++){
        cin >> tree[i];
    }
    construct();
    for(ll i = 0;i < m;i++){
        //printtree();
        ll p, q, r, s;
        cin >> p >> q >> r >> s;
        ll ma = max(p, q);
        ll mi = min(p, q);
        cout << sum(mi+leaf-1, ma+leaf-1, 1, leaf, leaf*2-1) << "\n";
        update(r, s);
    }
}
