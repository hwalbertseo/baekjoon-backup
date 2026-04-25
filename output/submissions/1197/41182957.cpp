#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge{
    int s, e, w;
};

int v, e;
vector<pair<int, int>> arr[100005];
vector<edge> ve;
int mm[100005];

int srch(int cur){
    if(mm[cur] == cur){
        return cur;
    }
    return mm[cur] = srch(mm[cur]);
}

void comb(int a, int b){
    a = srch(a);
    b = srch(b);

    if(a == b){
        return;
    }

    mm[a] = b;
}

bool comp(edge a, edge b){
    if(a.w == b.w){
        if(a.s == b.s){
            return a.e < b.e;
        }
        return a.s < b.s;
    }
    return a.w < b.w;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0;i < 100005;i++){
        mm[i] = i;
    }
    cin >> v >> e;
    for(int i =0;i < e;i++){
        int p, q, r;
        cin >> p >> q >> r;
        arr[p].push_back({q, r});
        arr[q].push_back({p, r});
        edge temp;
        temp.s = p;
        temp.e = q;
        temp.w = r;
        ve.push_back(temp);
    }
    sort(ve.begin(), ve.end(), comp);
    int ans = 0;
    for(int i = 0;i < ve.size();i++){
        edge temp = ve[i];
        if(srch(temp.s) == srch(temp.e)){
            continue;
        }
        ans += temp.w;
        comb(temp.s, temp.e);
    }
    cout << ans;
}
