#include <iostream>
#include <algorithm>

using namespace std;

int mm[100005];

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
    int g, p;
    cin >> g >> p;
    for(int j = 0;j < 100005;j++){
        mm[j] = j;
    }
    int ans = 0;
    bool stop = false;
    for(int i = 0;i < p;i++){
        int q;
        cin >> q;
        int ins = srch(q);
        if(ins == 0){
            stop = true;
        }
        else{
            if(stop){
                continue;
            }
            ans++;
            comb(ins, ins-1);
        }
    }
    cout << ans;
}
