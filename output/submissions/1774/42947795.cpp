#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <cstdio>

using namespace std;

int n, m;
int mm[100005];
vector<pair<int, int>> v;

struct edge{
    int a, b, r;
};

struct cmp{
    bool operator()(edge a, edge b){
        if(a.r == b.r){
            if(a.a == b.a) return a.b < b.b;
            return a.a < b.a;
        }
        return a.r > b.r;
    }
};


int srch(int a){
    if(a == mm[a]){
        return a;
    }
    return mm[a] = srch(mm[a]);
}

void comb(int a, int b){
    int p = srch(a);
    int q = srch(b);
    if(p==q){
        return;
    }
    mm[p] = q;
}

int main()
{
    for(int i = 0;i < 100005;i++){
        mm[i] = i;
    }
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        v.push_back({p, q});
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        comb(p-1, q-1);
    }
    priority_queue<edge, vector<edge>, cmp> pq;
    for(int i =0;i < n;i++){
        for(int j = i+1;j < n;j++){
            int dist = (v[i].first-v[j].first)*(v[i].first-v[j].first) + (v[i].second-v[j].second)*(v[i].second-v[j].second);
            edge temp = {i, j, dist};
            pq.push(temp);
        }
    }
    double ans = 0;
    while(!pq.empty()){
        int a = pq.top().a;
        int b = pq.top().b;
        int dist = pq.top().r;
        pq.pop();
        if(srch(a) == srch(b)){
            continue;
        }
        else{
            comb(a, b);
            ans += sqrt(dist);
            ans = round(ans*100)/100.0;
        }
    }
    printf("%.2f", ans);
}
