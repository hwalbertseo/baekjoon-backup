#include <iostream>
#include <map>
#include <set>

using namespace std;

int n, m;
map<int, int> enemy;
int pt[100005];
set<int> mult;

int srch(int cur){
    if(pt[cur] == cur){
        return cur;
    }
    return pt[cur] = srch(pt[cur]);
}

void comb(int a, int b){
    int p = srch(a);
    int q = srch(b);
    if(p == q){
        return;
    }
    pt[p] = q;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0;i < 100005;i++){
        pt[i] = i;
    }
    cin >> n >> m;
    for(int i = 0;i < m;i++){
        char p;
        int q, r;
        cin >> p >> q >> r;
        if(p == 'F'){
            comb(q, r);
        }
        else{
            if(enemy.count(q) == 0){
                enemy[q] = r;
            }
            if(enemy.count(r) == 0){
                enemy[r] = q;
            }
            comb(enemy[q], r);
            comb(enemy[r], q);
        }
    }
    for(int i = 1;i <= n;i++){
        //cout << i << " " << srch(i) << endl;
        mult.insert(srch(i));
    }
    cout << mult.size();
}
