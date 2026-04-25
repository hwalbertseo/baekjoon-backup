#include <iostream>
#define ll long long

using namespace std;

ll n = 1, m, k;
ll tree[4000005];
ll modnum = 1000000007;

void construct(){
    for(int i = n-1;i >= 1;i--){
        tree[i] = (tree[i*2] * tree[i*2 + 1])%modnum;
    }
}

void update(ll place, ll val){
    place += n-1;
    tree[place] = val;
    while(place >= 1){
        place /= 2;
        tree[place] = (tree[place*2] * tree[place*2 + 1])%modnum;
    }
}

ll time(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    if(R < nodeL || nodeR < L){
        return 1;
    }
    if(L <= nodeL && nodeR <= R){
        return tree[curnode];
    }
    ll mid = (nodeL + nodeR)/2;
    return (time(L, R, curnode*2, nodeL, mid) * time(L, R, curnode*2+1, mid+1, nodeR))%modnum;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t >> m >> k;
    while(n < t) n <<= 1;
    for(int i = 0;i < 4000005;i++){
        tree[i] = 1;
    }
    for(int i = n;i < n+t;i++){
        cin >> tree[i];
    }
    construct();
    /*
    for(int i = 1;i < 2*n;i++){
        cout << tree[i] << " ";
    }
    cout << endl;
    */
    for(int i = 0;i < m+k;i++){
        ll p, q, r;
        cin >> p >> q >> r;
        if(p == 1){
            update(q, r);
        }
        else{
            cout << time(q+n-1, r+n-1, 1, n, n*2-1) << "\n";
        }
    }

}
