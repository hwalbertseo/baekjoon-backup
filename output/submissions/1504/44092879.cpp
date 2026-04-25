#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long

using namespace std;

ll n, m;
ll mm[100005];
vector<pair<ll, ll>> graph[100005];
ll INF = 2e9;

struct cmp{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second < b.second;
    }
};

void Dijkstra(ll start){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    mm[start] = 0;
    pq.push({start, 0});
    while(!pq.empty()){
        ll cur = pq.top().first;
        int wei = pq.top().second;
        pq.pop();
        if(mm[cur] < wei){
            continue;
        }
        for(ll i = 0;i < graph[cur].size();i++){
            ll nxt = graph[cur][i].first;
            ll dist = wei+graph[cur][i].second;
            if(mm[nxt] > dist){
                pq.push({nxt, dist});
                mm[nxt] = dist;
            }
        }
    }
}

void init(){
    for(ll i = 0;i < 100005;i++){
        mm[i] = INF;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(ll i = 0;i < m;i++){
        ll p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }
    ll p1, p2;
    cin >> p1 >> p2;
    ll ans1 = 0, ans2 = 0;
    init();
    Dijkstra(1);
    ans1 += mm[p1];
    ans2 += mm[p2];
    //cout << ans1 << " " << ans2 << endl;
    init();
    Dijkstra(p1);
    ans1 += mm[p2];
    ans2 += mm[n];
    //cout << ans1 << " " << ans2 << endl;
    init();
    Dijkstra(p2);
    ans1 += mm[n];
    ans2 += mm[p1];
    //cout << ans1 << " " << ans2 << endl;
    int ans = min(ans1, ans2);
    if(ans >= INF){
        cout << -1;
    }
    else{
        cout << ans;
    }
}
