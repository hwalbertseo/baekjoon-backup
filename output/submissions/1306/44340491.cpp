#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m, leaf = 1;
ll tree[4000005];

void construct(){
    for(ll i = leaf-1;i > 0;i--){
        tree[i] = max(tree[i*2], tree[i*2+1]);
    }
}

ll findmax(ll L, ll R, ll cur, ll Lnode, ll Rnode){
    if(R < Lnode || L > Rnode){
        return 0;
    }
    else if(L <= Lnode && Rnode <= R){
        return tree[cur];
    }
    else{
        ll mid = (Lnode + Rnode)/2;
        return max(findmax(L, R, cur*2, Lnode, mid), findmax(L, R, cur*2+1, mid+1, Rnode));
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while(leaf < n) leaf <<= 1;
    for(ll i = leaf;i < leaf+n;i++){
        cin >> tree[i];
    }
    construct();

    for(ll i = leaf+m-1;i < leaf+n-m+1;i++){
        cout << findmax(i-m+1, i+m-1, 1, leaf, leaf*2-1) << " ";
    }
}
