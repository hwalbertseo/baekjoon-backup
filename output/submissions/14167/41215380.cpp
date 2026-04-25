#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

struct edge{
    ll first, second, w;
};

ll n;
pair<ll, ll> arr[1005];
vector<pair<ll, ll>> graph[1005];
vector<edge> v;
int mm[1005];

bool comp(edge a, edge b){
    if(a.w == b.w){
        if(a.first == b.first){
            return a.second < b.second;
        }
        return a.first < b.first;
    }
    return a.w < b.w;
}

int srch(ll cur){
    if(mm[cur] == cur){
        return cur;
    }
    return mm[cur] = srch(mm[cur]);
}

void comb(ll a, ll b){
    ll p = srch(a);
    ll q = srch(b);
    if(p == q){
        return;
    }
    mm[p] = q;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0;i < 1005;i++){
        mm[i] = i;
    }
    cin >> n;
    for(ll i = 1;i <= n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p, q};
    }
    for(ll i = 1;i <= n;i++){
        int x1 = arr[i].first;
        int y1 = arr[i].second;
        for(ll j = i+1;j <= n;j++){
            int x2 = arr[j].first;
            int y2 = arr[j].second;
            ll dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            graph[i].push_back({j, dist});
            graph[j].push_back({i, dist});
            edge temp;
            temp.first = i; temp.second = j; temp.w = dist;
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end(), comp);
    int mx = -1;
    for(int i = 0;i < v.size();i++){
        int st = v[i].first;
        int ed = v[i].second;
        int w = v[i].w;
        if(srch(st) == srch(ed)){
            continue;
        }
        else{
            mx = w;
            comb(st, ed);
        }
    }
    cout << mx;
}
