#include <iostream>
#define ll long long

using namespace std;

ll segtree[400005];
ll treen = 1;

void build(){
    for(int i = treen-1;i > 0;i--){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}

void update(int r){
    for(int i = r/2;i > 0;i /= 2){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}

void updatetree(int beg, int fin, int r){
    beg += treen-1;
    fin += treen-1;
    segtree[beg] += r;
    update(beg);
    if(fin < 2*treen){
        segtree[fin+1] -= r;
        update(fin+1);
    }
}

int srch(int L, int R, int curnode, int nodeL, int nodeR){
    if(L <= nodeL && nodeR <= R){
        return segtree[curnode];
    }
    else if(L > nodeR || R < nodeL){
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
    cout <<"\n";
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    while(treen < n) treen <<= 1;
    int val = 0;
    for(int i = 0;i < n;i++){
        int p;
        cin >> p;
        segtree[treen+i] = p - val;
        val = p;
    }
    //printtree();
    build();
    //printtree();
    int q;
    cin >> q;
    for(int i = 0;i < q;i++){
        int a;
        cin >> a;
        if(a == 1){
            int b, c, d;
            cin >> b >> c >> d;
            updatetree(b, c, d);
        }
        else{
            int b;
            cin >> b;
            cout << srch(treen, treen+b-1, 1, treen, treen*2-1) << "\n"; 
        }
        //printtree();
    }
}