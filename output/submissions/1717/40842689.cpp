#include <iostream>

using namespace std;

int n, m;
int mm[1000005];

int srch(int cur){
    if(mm[cur] == cur){
        return cur;
    }
    mm[cur] = srch(mm[cur]);
    return mm[cur];
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
    for(int i = 0;i < 1000005;i++){
        mm[i] = i;
    }
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        int p, q, r;
        cin >> p >> q >> r;
        if(p == 0){
            comb(q, r);
        }
        else{
            if(srch(q) == srch(r)){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}
