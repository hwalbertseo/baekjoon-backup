#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int b, e, p, n, m;
int INF = 2e9;
int c[3][40005];
int len[3];
vector<int> arr[40005];

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

void dijkstra(int start, int cow){
    priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;
    c[cow][start] = 0;
    pq.push({start, 0});
    while(!pq.empty()){
        int dist = pq.top().second;
        int cur = pq.top().first;
        pq.pop();
        if(c[cow][cur] < dist){
            continue;
        }
        for(int i = 0;i < arr[cur].size();i++){
            int d = dist + len[cow];
            int nxt = arr[cur][i];
            if(c[cow][nxt] > d){
                c[cow][nxt] = d;
                pq.push({nxt, d});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0;i < 40005;i++){
        for(int j = 0;j < 3;j++){
            c[j][i] = INF;
        }
    }
    cin >> len[0] >> len[1] >> len[2] >> n >> m;
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        arr[p].push_back(q);
        arr[q].push_back(p);
    }
    dijkstra(1, 0);
    dijkstra(2, 1);
    dijkstra(n, 2);
    int ans = c[0][n] + c[1][n];
    for(int i = 1;i <= n;i++){
        ans = min(ans, c[0][i] + c[1][i] + c[2][i]);
    }
    cout << ans;
}
