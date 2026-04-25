#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int, int>> graph[100005];
int mm[100005];
int INF = 2e9;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

void dijkstra(int beg){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({beg, 0});
    while(!pq.empty()){
        int curx = pq.top().first;
        int cand = pq.top().second;
        pq.pop();
        if(mm[curx] < cand){
            continue;
        }
        for(int i = 0;i < graph[curx].size();i++){
            int nxt = graph[curx][i].first;
            int nd = cand+graph[curx][i].second;
            if(nd < mm[nxt]){
                mm[nxt] = nd;
                pq.push({nxt, nd});
            }
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0;i < 100005;i++){
        mm[i] = INF;
    }
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int p, q, r;
        cin >> p >> q >> r;
        graph[p].push_back({q, r});
        graph[q].push_back({p, r});
    }
    dijkstra(1);
    cout << mm[n];
}
