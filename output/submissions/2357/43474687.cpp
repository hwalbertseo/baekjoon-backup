#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll n = 1, m;
ll maxtree[4000005];
ll mintree[4000005];

void construct(){
    for(int i = n-1;i >= 1;i--){
        maxtree[i] = max(maxtree[i*2], maxtree[i*2+1]);
        mintree[i] = min(mintree[i*2], mintree[i*2+1]);
    }
}

ll srchmax(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    if(R < nodeL || L > nodeR){
        return 0;
    }
    if(L <= nodeL && nodeR <= R){
        return maxtree[curnode];
    }
    ll mid = (nodeL + nodeR) / 2;
    return max(srchmax(L, R, curnode*2, nodeL, mid), srchmax(L, R, curnode*2+1, mid+1, nodeR));
}

ll srchmin(ll L, ll R, ll curnode, ll nodeL, ll nodeR){
    if(R < nodeL || L > nodeR){
        return 10000000000;
    }
    if(L <= nodeL && nodeR <= R){
        return mintree[curnode];
    }
    ll mid = (nodeL + nodeR) / 2;
    return min(srchmin(L, R, curnode*2, nodeL, mid), srchmin(L, R, curnode*2+1, mid+1, nodeR));
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t >> m;
    for(ll i = 0;i < 4000005;i++){
        mintree[i] = 10000000000;
    }
    while(n < t) n <<= 1;
    for(int i = n;i < n+t;i++){
        ll p;
        cin >> p;
        maxtree[i] = p;
        mintree[i] = p;
    }
    construct();
/*
    for(int i = 1;i < n*2-1;i++){
        cout << mintree[i] << " ";
    }
    cout << endl;
    cout << endl;
*/
    for(int i = 0;i < m;i++){
        ll p, q;
        cin >> p >> q;
        cout << srchmin(p+n-1, q+n-1, 1, n, 2*n-1) << " " << srchmax(p+n-1, q+n-1, 1, n, 2*n-1) << "\n";
    }
}
