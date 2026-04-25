#include <iostream>
#define ll long long

using namespace std;
int segtree[400000];
int n = 1;

void build(int s){
    for(int i = n;i < n+s;i++){
        segtree[i] = 1;
    }
    for(int i = n-1;i > 0;i--){
        segtree[i] = segtree[i*2] + segtree[i*2+1];
    }
}


int srch(int curnode, int x){
    //cout << curnode << "\n";
    if(curnode * 2 >= 2*n){
        segtree[curnode]--;
        for(int i = curnode/2; i > 0;i /= 2){
            segtree[i] = segtree[i*2] + segtree[i*2+1];
        }
        return curnode-n+1;
    }
    else{
        int left = segtree[curnode*2];
        int right = segtree[curnode*2+1];
        if(left >= x){
            return srch(curnode*2, x);
        }
        else{
            return srch(curnode*2+1, x-left);
        }
    }
}

void printtree(){
    for(int i = 1;i < n*2;i++){
        cout << segtree[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int p, q;
    cin >> p >> q;
    while(n < p) n <<= 1;
    build(p);
    int freq = q;
    cout << "<";
    while(segtree[1] > 0){
        while(freq > segtree[1]){
            freq -= segtree[1];
        }
        int ans = srch(1,freq);
        cout << ans;
        if(segtree[1] == 0){
            continue;
        }
        else{
            cout << ", ";
        }
        freq = freq + q - 1;
        //printtree();
    }
    cout <<">";
}