#include <iostream>

using namespace std;

int n, m;
int mm[500005];

int srch(int a){
    if(mm[a] == a){
        return a;
    }
    return mm[a] = srch(mm[a]);
}

void comb(int a, int b){
    int p = srch(a);
    int q = srch(b);

    if(p == q){
        return;
    }

    mm[p] = q;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    int ans = 0;
    for(int i = 0;i < 500005;i++){
        mm[i] = i;
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        if(srch(p) == srch(q) && ans == 0){
            ans = i+1;
        }
        else{
            comb(p, q);
        }
    }
    cout << ans;
}
