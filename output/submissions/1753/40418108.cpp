#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int INF = 2e9;
int v, e, k;
vector<pair<int, int>> arr[20005];
int m[20005];

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
};

void dijkstra(int start){
    m[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({start, 0});

    while(!pq.empty()){
        int d = pq.top().second;
        int cur = pq.top().first;
        pq.pop();

        if(m[cur] < d){
            continue;
        }
        for(int i = 0;i < arr[cur].size();i++){
            int nxt = arr[cur][i].first;
            int dist = arr[cur][i].second + d;
            if(dist < m[nxt]){
                m[nxt] = dist;
                //cout << nxt << " " << dist << "\n";
                pq.push({nxt, dist});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> v >> e >> k;
    for(int i = 0;i < e;i++){
        int p, q, r;
        cin >> p >> q >> r;
        arr[p].push_back({q, r});
    }
    for(int i = 1;i <= v;i++){
        m[i] = INF;
    }
    dijkstra(k);
    for(int i = 1;i <= v;i++){
        if(m[i] == INF){
            cout << "INF\n";
            continue;
        }
        cout << m[i] << "\n";
    }
}
