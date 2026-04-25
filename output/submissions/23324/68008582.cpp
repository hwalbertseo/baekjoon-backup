#include <iostream>
#include <vector>
#define ll long long

using namespace std;

ll uf[3000000];
ll numa, numb;
ll nodea, nodeb;

ll srch(ll cur){
    if(uf[cur] == cur){
        return cur;
    }
    return uf[cur] = srch(uf[cur]);
}

void comb(ll a, ll b){
    ll p = srch(a);
    ll q = srch(b);
    if(p == q){
        return;
    }
    uf[p] = q;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m, w;
    cin >> n >> m >> w;
    for(ll i = 0;i < 3000000;i++){
        uf[i] = i;
    }
    for(ll i = 0;i < m;i++){
        ll p, q;
        cin >> p >> q;
        if(i+1 == w){
            nodea = p;
            nodeb = q;
            continue;
        }
        else{
            comb(p, q);
        }
    }
    //cout << nodea << " " << nodeb << "\n";
    //cout << srch(nodea) << " " << srch(nodeb) << "\n";
    for(ll i = 1;i < n+1;i++){
        //cout << srch(uf[i]) << "\n";
        if(srch(i) == srch(nodea)){
            numa++;
        }
        else{
            numb++;
        }
    }
    cout << numa * numb;
}