#include <iostream>
#include <set>
#include <map>
#define ll long long

using namespace std;

int c, n;

struct dot{
    ll num;
    ll se;
    ll idx;
};

bool comp(dot a, dot b){
    if(a.num == b.num){
        if(a.se == b.se){
            return a.idx < b.idx;
        }
        return a.se < b.se;
    }
    return a.num < b.num;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    set<dot, decltype(&comp)> sweep(&comp);
    map<ll, ll> e;
    cin >> c >> n;
    for(int i = 0;i < c;i++){
        ll p;
        cin >> p;
        sweep.insert({p, 0, i});
    }
    for(int i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        e[i] = q;
        sweep.insert({p, -1, i});
        sweep.insert({q, 1, i});
    }
    ll cnt = 0;

    set<pair<ll, ll>> active;
    for(dot i: sweep){
        if(i.se == 0){
            if(active.empty()){
                continue;
            }
            else{
                auto rec = active.begin();
                ll m = 2e9;
                for(auto it = active.begin();it != active.end();it++){
                    if((*it).second < m){
                        m = (*it).second;
                        rec = it;
                    }
                }
                active.erase(rec);
                cnt++;
            }
        }
        else if(i.se == -1){
            active.insert({i.idx, e[i.idx]});
        }
        else if(i.se == 1){
            active.erase({i.idx, e[i.idx]});
        }
    }
    cout << cnt;
}
/*
5 5
7
8
6
2
9
2 9
2 5
4 9
0 3
8 13
*/
