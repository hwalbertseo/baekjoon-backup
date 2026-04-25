#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

struct path{
    ll beg, fin, w;
};

ll n, m;
int gen[1005];
vector<path> v;
ll visit[1005];
ll uf[1005];

ll srch(ll cur){
    if(cur == uf[cur]){
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

bool cmp(path a, path b){
    if(a.w == b.w){
        if(a.fin == b.fin){
            return a.beg < b.beg;
        }
        return a.fin < b.fin;
    }
    return a.w < b.w;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(ll i = 0;i < 1005;i++){
        uf[i] = i;
    }
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        char temp;
        cin >> temp;
        if(temp == 'W'){
            gen[i] = 1;
        }
        else{
            gen[i] = 0;
        }
    }
    for(ll i = 0;i < m;i++){
        ll p, q, r;
        cin >> p >> q >> r;
        path temp = {p, q, r};
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), cmp);
    ll ans = 0;
    for(ll i = 0;i < v.size();i++){
        ll beg = v[i].beg;
        ll fin = v[i].fin;
        ll w = v[i].w;
        //cout << beg << " " << fin << " " << w << "\n";
        if(srch(beg) != srch(fin)){
            if(gen[beg] == gen[fin]){
                continue;
            }
            visit[beg] = 1;
            visit[fin] = 1;
            //cout << beg << " " << fin << endl;
            ans += w;
            comb(beg, fin);
        }
    }
    for(ll i = 1;i <= n;i++){
        if(visit[i] == 0){
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}
/*
5 7
M W W W W
1 2 12
1 3 10
4 2 5
5 2 5
2 5 10
3 4 3
5 4 7
*/
