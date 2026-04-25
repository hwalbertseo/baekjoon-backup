#include <iostream>
#define ll long long

using namespace std;

ll num = 1000000007;

pair<ll, ll> segtree[3000000];
ll treen = 1;

pair<ll, ll> calc(pair<ll, ll> leftnode, pair<ll, ll> rightnode){
    ll a = leftnode.first;
    ll b = leftnode.second;
    ll c = rightnode.first;
    ll d = rightnode.second;
    pair<ll, ll> temp;
    temp.first = (a*c) % num;
    temp.second = (b*c % num) + (d % num);
    temp.second %= num;
    return temp;
}

void build(){
    for(ll i = treen-1;i > 0;i--){
        segtree[i] = calc(segtree[i*2], segtree[i*2+1]);
    }
}

void replace(ll idx, pair<ll, ll> val){
    segtree[idx+treen-1] = val;
    for(ll i = (idx+treen-1)/2;i > 0;i /= 2){
        segtree[i] = calc(segtree[i*2], segtree[i*2+1]);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0;i < 3000000;i++){
        segtree[i] = {1,0};
    }
    ll p, q;
    cin >> p >> q;
    while(treen < p) treen <<= 1;
    for(ll i = 0;i < p;i++){
        char c; ll n;
        cin >> c >> n;
        if(c == '+'){
            segtree[treen+i] = {1, n};
        }
        else{
            segtree[treen+i] = {n, 0};
        }
    }
    build();
    for(ll i = 0;i < q;i++){
        char c; ll n, m;
        cin >> n >> c >> m;
        if(c == '+'){
            replace(n, {1, m});
        }
        else{
            replace(n, {m, 0});
        }
        cout << segtree[1].second << "\n";
    }
}