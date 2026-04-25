#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

int INF = 2e9;
vector<pair<int, int>> arr[100005];
vector<pair<int, int>> arr2[100005];
int mm[100005];
int mm2[100005];

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    mm[start] = 0;
    pq.push({start, 0});
    while(!pq.empty()){
        int d = pq.top().second;
        int cur = pq.top().first;
        pq.pop();
        if(d > mm[cur]){
            continue;
        }
        for(int i = 0;i < arr[cur].size();i++){
            int nxt = arr[cur][i].first;
            int dist = arr[cur][i].second + d;
            if(dist < mm[nxt]){
                mm[nxt] = dist;
                pq.push({nxt, dist});
            }
        }
    }
}

void dijkstra2(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    mm2[start] = 0;
    pq.push({start, 0});
    while(!pq.empty()){
        int d = pq.top().second;
        int cur = pq.top().first;
        pq.pop();
        if(d > mm2[cur]){
            continue;
        }
        for(int i = 0;i < arr2[cur].size();i++){
            int nxt = arr2[cur][i].first;
            int dist = arr2[cur][i].second + d;
            if(dist < mm2[nxt]){
                mm2[nxt] = dist;
                pq.push({nxt, dist});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, x;
    cin >> n >> m >> x;
    for(int i = 0;i < m;i++){
        int p, q, r;
        cin >> p >> q >> r;
        arr[q].push_back({p,r});
        arr2[p].push_back({q, r});
    }
    for(int i = 0;i <= n;i++){
        mm[i] = INF;
        mm2[i] = INF;
    }
    dijkstra(x);
    dijkstra2(x);
    int mi = -1;
    for(int i = 1;i <= n;i++){
        if(mm[i] + mm2[i] > mi){
            mi = mm[i] + mm2[i];
        }
    }
    cout << mi;
}
