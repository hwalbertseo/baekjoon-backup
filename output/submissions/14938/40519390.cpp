#include <iostream>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

ll n, m, r;
vector<pair<ll , ll>> arr[100005];
ll item[1005];
ll mm[1005][1005];
ll INF = 2e9;

struct cmp{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

void dijkstra(ll start){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    mm[start][start] = 0;
    pq.push({start, 0});

    while(!pq.empty()){
        ll d = pq.top().second;
        ll cur = pq.top().first;
        pq.pop();
        if(d > mm[start][cur]){
            continue;
        }
        for(ll i = 0;i < arr[cur].size();i++){
            ll dist = d+arr[cur][i].second;
            ll nxt = arr[cur][i].first;
            if(dist < mm[start][nxt]){
                mm[start][nxt] = dist;
                pq.push({nxt, dist});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> r;
    for(ll i = 1;i <= n;i++){
        cin >> item[i];
    }
    for(ll i = 0;i<r;i++){
        ll p, q, rr;
        cin >> p >> q >> rr;
        arr[p].push_back({q, rr});
        arr[q].push_back({p, rr});
    }
    for(ll i = 0;i <= n;i++){
        for(ll j = 0;j <= n;j++){
            mm[i][j] = INF;
        }
    }
    for(ll i = 1;i <= n;i++){
        dijkstra(i);
    }
    ll cnt = -1;
    for(ll i = 1;i <= n;i++){
        ll num = 0;
        for(ll j = 1;j <= n;j++){
            if(mm[i][j] <= m){
                num += item[j];
            }
        }
        if(num > cnt){
            cnt = num;
        }
    }
    /*
    for(ll i = 1;i <= n;i++){
        for(ll j = 1;j <= n;j++){
            cout << mm[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << cnt;
    return 0;
}
