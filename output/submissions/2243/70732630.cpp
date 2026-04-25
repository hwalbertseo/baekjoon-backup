#include <iostream>
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>

using namespace std;
int segtree[4000005];
int treen = 1;

void update(int q, int r){
    int idx = treen+q;
    segtree[idx] += r;
    for(int i = idx/2;i > 0;i /= 2){
        segtree[i] = segtree[i*2] + segtree[i*2 + 1];
    }
}

int get(int num, int curnode){
    if(curnode * 2 >= treen*2){
        return curnode - treen;
    }
    if(segtree[curnode*2] >= num){
        return get(num, curnode*2);
    }
    else{
        return get(num-segtree[curnode*2], curnode*2+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    while(treen < 1000000) treen <<= 1;
    for(int i = 0;i < n;i++){
        int p;
        cin >> p;
        if(p == 2){
            int q, r;
            cin >> q >> r;
            update(q, r);
        }
        else{
            int q;
            cin >> q;
            int ans = get(q,1);
            cout << ans << "\n";
            update(ans, -1);
        }
    }
}