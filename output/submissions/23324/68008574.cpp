#include <iostream>
#include <vector>

using namespace std;

int uf[3000000];
int numa, numb;
int nodea, nodeb;

int srch(int cur){
    if(uf[cur] == cur){
        return cur;
    }
    return uf[cur] = srch(uf[cur]);
}

void comb(int a, int b){
    int p = srch(a);
    int q = srch(b);
    if(p == q){
        return;
    }
    uf[p] = q;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, w;
    cin >> n >> m >> w;
    for(int i = 0;i < 3000000;i++){
        uf[i] = i;
    }
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        if(i+1 == w){
            nodea = p;
            nodeb = q;
            continue;
        }
        else{
            comb(p, q);
        }
    }
    //cout << nodea << " " << nodeb << "\n";
    //cout << srch(nodea) << " " << srch(nodeb) << "\n";
    for(int i = 1;i < n+1;i++){
        //cout << srch(uf[i]) << "\n";
        if(srch(i) == srch(nodea)){
            numa++;
        }
        else{
            numb++;
        }
    }
    cout << numa * numb;
}