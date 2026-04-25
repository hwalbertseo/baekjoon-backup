#include <iostream>
#include <vector>

using namespace std;

int n, m;
int mm[100005];

int srch(int a){
    if(mm[a] == a){
        return a;
    }
    else{
        return mm[a] = srch(mm[a]);
    }
}

void comb(int a, int b){
    int p = srch(a);
    int q = srch(b);
    if(p==q){
        return;
    }
    mm[p] = q;
}

int main()
{
    for(int i = 0;i < 100005;i++){
        mm[i] = i;
    }
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            int p;
            cin >> p;
            if(p){
                comb(i, j);
            }
        }
    }
    bool pos = true;
    int save;
    for(int i = 0;i < m;i++){
        int p;
        cin >> p;
        if(i == 0) save = srch(p);
        else{
            if(srch(p) == save){
                continue;
            }
            else{
                pos = false;
                break;
            }
        }
    }
    cout << (pos ? "YES" : "NO");
}
