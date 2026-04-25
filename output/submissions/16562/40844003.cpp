#include <iostream>
#include <set>

using namespace std;

int n, m, k;
int mm[20005];
int price[20005];
set<int> s;

int srch(int cur){
    if(mm[cur] == cur){
        return cur;
    }
    return mm[cur] = srch(mm[cur]);
}

void comb(int a, int b){
    int p = srch(a);
    int q = srch(b);
    if(p == q){
        return;
    }
    if(price[p] < price[q]){
        mm[q] = p;
    }
    else{
        mm[p] = q;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    for(int i = 0;i < 20005;i++){
        mm[i] = i;
    }
    cin >> n >> m >> k;
    for(int i = 0;i < n;i++){
        cin >> price[i];
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        comb(p-1, q-1);
    }
    for(int i = 0;i < n;i++){
        s.insert(srch(i));
    }
    int ans = 0;
    for(int i : s){
        ans += price[i];
    }
    if(ans > k){
        cout << "Oh no";
    }
    else{
        cout << ans;
    }
}
