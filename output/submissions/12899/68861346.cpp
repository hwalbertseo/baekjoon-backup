#include <iostream>

using namespace std;

int segtree[8000000];
int child = 1;

void insert(int k){
    int idx = k + child-1;
    segtree[idx] += 1;
    for(int i = idx/2;i > 0;i /= 2){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}

int srch(int curnode, int x){
    if(curnode*2 > child*2-1){
        int val = segtree[curnode];
        segtree[curnode] -= 1;
        for(int i = curnode/2;i > 0;i /= 2){
            segtree[i] = segtree[i*2] + segtree[i*2+1];
        }
        return curnode-child+1;
    }
    if(segtree[curnode*2] < x){
        return srch(curnode*2 + 1, x - segtree[curnode*2]);
    }
    else{
        return srch(curnode*2, x);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    while(child < 2000000) child <<= 1;
    //child = 8;
    for(int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        if(a == 1){
            insert(b);
        }
        else{
            cout << srch(1, b) << "\n";
        }
        /*
        for(int i = 1;i < child*2;i++){
            cout << segtree[i] << " ";
        }
        cout << "\n";
        */
    }
}