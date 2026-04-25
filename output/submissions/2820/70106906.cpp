#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

struct employee{
    int ind;
    int wage;
    int sup;
};

bool comp(employee a, employee b){
    if(a.sup == b.sup){
        return a.ind < b.ind;
    }
    return a.sup < b.sup;
}


int segtree[2000005];
int hasharr[500005];
employee inp[500005];
pair<int, int> range[500005];
int treen = 1;
vector<int> graph[500005];

void update(int ind){
    for(int i = ind/2;i > 0;i /= 2){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}

void updatetree(int b, int e, int r){
    b += treen-1;
    e += treen-1;
    segtree[b] += r;
    update(b);
    segtree[e+1] -= r;
    //cout << "updated " << b << " into " << segtree[b] << "\n";
    //cout << "updated " << e+1 << " into " << segtree[e+1] << "\n";
    if(e+1 < treen*2){
        update(e+1);
    }
}

void dfs(int curnode, int val){
    //cout << "curnode: " << curnode << "\n";
    int cur = hasharr[curnode];
    if(range[cur].second == 0){
        return;
    }
    updatetree(range[cur].first, range[cur].second, val);
    //cout << "updaetd "<< curnode << "\n";
    for(int i = 0;i < graph[curnode].size();i++){
        int next = graph[curnode][i];
        dfs(next, val);
    }
    return;
}

int srch(int L, int R, int curnode, int nodeL, int nodeR){
    if(L <= nodeL && nodeR <= R){
        return segtree[curnode];
    }
    else if(R < nodeL || nodeR < L){
        return 0;
    }
    else{
        int mid = nodeL+nodeR; mid /= 2;
        return srch(L, R, curnode*2, nodeL, mid) + srch(L, R, curnode*2+1, mid+1, nodeR);
    }
}

void printtree(){
    for(int i = 1;i < treen*2;i++){
        cout << segtree[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    while(treen < n) treen <<= 1;
    int Mirko;
    cin >> Mirko;
    inp[0] = {1, Mirko, 0};
    for(int i = 1;i < n;i++){
        int p, q;
        cin >> p >> q;
        inp[i] = {i+1, p, q};
        graph[q].push_back(i+1);
    }
/*
    for(int i = 1;i <= n;i++){
        cout << i << ": "; 
        for(int j = 0;j <graph[i].size();j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
*/
    sort(inp+1, inp+n, comp);
    hasharr[1] = 1;
    for(int i = 1;i < n;i++){
        hasharr[inp[i].ind] = i+1;
        if(inp[i-1].sup != inp[i].sup){
            range[inp[i].sup].first = i+1;
        }
        if(range[inp[i].sup].second < i+1){
            range[inp[i].sup].second = i+1;
        }
    }
    
    //check
    /*
    for(int i = 0;i < n;i++){
        cout << inp[i].ind << " " << inp[i].wage << " " << inp[i].sup << "\n";
    }
    
    for(int i = 1;i <= n;i++){
        cout << range[i].first << " " << range[i].second << "\n";    
    }
    ///*
    cout << "\n";
    for(int i = 0;i < n;i++){
        cout << i+1 << " " << hasharr[i+1] << "\n";    
    }
    */
    //build segtree
    int var = 0;
    for(int i = treen;i < treen+n;i++){
        segtree[i] = inp[i-treen].wage - var;
        var += segtree[i];
    }
    for(int i = treen-1;i > 0;i--){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
    //take query
    //printtree();
    for(int i = 0;i < m;i++){
        char f;
        cin >> f;
        if(f == 'p'){
            int emp, change;
            cin >> emp >> change;
            dfs(emp, change);
        }
        else{
            int get;
            cin >> get;
            get = hasharr[get];
            //cout << "get: " << get << "\n";
            //cout << treen << " " << treen+get-1 << "\n";
            cout << srch(treen, treen+get-1, 1, treen, treen*2-1) << "\n";
        }
        //printtree();
    }
}