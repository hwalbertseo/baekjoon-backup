#include <iostream>
#define ll long long

using namespace std;

ll tree[4000005];
ll n = 1, m, k;

void construct(){
    for(ll i = n-1;i >= 0;i--){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

void update(int place, int val){
    //cout << "ent";
    place += n-1;
    tree[place] = val;
    for(int i = place/2;i > 0;i /= 2){
        tree[i] = tree[i*2] + tree[i*2+1];
    }
}

ll sum(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    //cout << L << " " << R << " " << nodeL << " " << nodeR << "\n";
    if(R < nodeL || nodeR < L){
        return 0;
    }
    if(L <= nodeL && nodeR <= R){
        return tree[curnode];
    }
    ll mid = (nodeL + nodeR)/2;
    return sum(L, R, curnode*2, nodeL, mid) + sum(L, R, curnode*2+1, mid+1, nodeR);
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t >> m >> k;
    while(n < t) n <<= 1;
    //cout << n;
    for(ll i = n;i < n+t;i++){
        cin >> tree[i];
    }
    //cout << "he";
    construct();
    for(ll i = 0;i < m+k;i++){
        ll p, q, r;
        cin >> p >> q >> r;
        if(p == 1){
            update(q, r);
/*
            for(int i = 0;i < 16;i++){
                cout << tree[i] << " ";
            }
            cout << endl;
*/
        }
        else{
            cout << sum(q+n-1, r+n, 1, n, n*2-1) << "\n";
        }
    }

}
