#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, r;
vector<pair<int, int>> arr[100005];
int item[100005];
int mm[1005][1005];
int INF = 2e9;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

void dijkstra(int start){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    mm[start][start] = 0;
    pq.push({start, 0});
    //cout << start << "\n";

    while(!pq.empty()){
        int d = pq.top().second;
        int cur = pq.top().first;
        pq.pop();
        if(d > mm[start][cur]){
            continue;
        }
        for(int i = 0;i < arr[cur].size();i++){
            int dist = d+arr[cur][i].second;
            int nxt = arr[cur][i].first;
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
    for(int i = 1;i <= n;i++){
        cin >> item[i];
    }
    for(int i = 0;i<r;i++){
        int p, q, r;
        cin >> p >> q >> r;
        arr[p].push_back({q, r});
        arr[q].push_back({p, r});
    }
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= n;j++){
            mm[i][j] = INF;
        }
    }
    for(int i = 1;i <= n;i++){
        dijkstra(i);
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++){
        int num = 0;
        for(int j = 1;j <= n;j++){
            if(mm[i][j] < m){
                num += item[j];
            }
        }
        if(num > cnt){
            cnt = num;
        }
    }
    cout << cnt;
}
