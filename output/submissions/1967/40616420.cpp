#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
vector<pair<int, int>> arr[10005];
int mm[10005];

int INF = 2e9;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second > b.second;
    }
};

void init(){
    for(int i = 0;i < 10005;i++){
        mm[i] = INF;
    }
}

void dijkstra(int start){
    mm[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({start, 0});
    while(!pq.empty()){
        int cur = pq.top().first;
        int d = pq.top().second;
        pq.pop();
        if(d > mm[cur]){
            continue;
        }
        for(int i = 0;i < arr[cur].size();i++){
            int nxt = arr[cur][i].first;
            int dist = arr[cur][i].second + d;
            if(mm[nxt] > dist){
                mm[nxt] = dist;
                pq.push({nxt, dist});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i = 0;i < n-1;i++){
        int p, q, r;
        cin >> p >> q >> r;
        arr[p].push_back({q, r});
        arr[q].push_back({p, r});
    }
    init();
    dijkstra(1);
    int mx = -1;
    int bn;
    for(int i = 1;i <= n;i++){
        if(mm[i] > mx){
            mx = mm[i];
            bn = i;
        }
    }
    init();
    dijkstra(bn);
    for(int i = 1;i <= n;i++){
        if(mm[i] > mx){
            mx = mm[i];
            bn = i;
        }
    }
    cout << mx;
}
