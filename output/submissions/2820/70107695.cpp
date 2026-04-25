#include <iostream>
#include <vector>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;

int segtree[2000005];
pii ett[500005];
vector<int> graph[500005];
int treen = 1;
int wage[500005];

int sttind = 0;
void dfs(int curnode){
    ett[curnode].first = ++sttind;
    if(graph[curnode].empty()){
        ett[curnode].second = sttind;
        return;
    }
    for(int next : graph[curnode]){
        dfs(next);
    }
    ett[curnode].second = sttind;
}

void updatepoint(int idx){
    for(int i = idx/2;i > 0;i /= 2){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}

void updatetree(int l, int r, int val){
    l += treen;
    r += treen;
    segtree[l] += val;
    updatepoint(l);
    segtree[r] -= val;
    if(r < treen*2){
        updatepoint(r);
    }
}

int srch(int L, int R, int curnode, int nodeL, int nodeR){
    if(L <= nodeL && nodeR <= R){
        return segtree[curnode];
    }
    else if(R < nodeL || nodeR < L){
        return 0;
    }
    else{
        int mid = (nodeL+nodeR)/2;
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
    wage[1] = Mirko;
    for(int i = 1;i < n;i++){
        int q;
        cin >> wage[i+1] >> q;
        graph[q].push_back(i+1);
    }
    dfs(1);
    for(int i = treen;i < treen+n;i++){
        segtree[ett[i-treen+1].first+treen-1] = wage[i-treen+1];
    }
    for(int i = treen+n-1;i >= treen;i--){
        segtree[i] -= segtree[i-1];
    }
    for(int i = treen-1;i > 0;i--){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
    //printtree();
    for(int i = 0;i < m;i++){
        char c; cin >> c;
        if(c == 'p'){
            int head, val;
            cin >> head >> val;
            updatetree(ett[head].first, ett[head].second, val);
        }
        else{
            int idx;
            cin >> idx;
            idx = ett[idx].first;
            cout << srch(treen, treen+idx-1, 1, treen, treen*2-1) << "\n";
        }
        //printtree();
    }
}