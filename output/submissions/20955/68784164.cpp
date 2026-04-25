// Online C++ compiler to run C++ program online
#include <iostream>
#include <set>

using namespace std;

int arr[100005];

int srch(int a){
    if(arr[a] == a){
        return a;
    }
    else{
        return arr[a] = srch(arr[a]);
    }
}

void comb(int a, int b){
    int p = srch(a);
    int q = srch(b);
    if(p == q){
        return;
    }
    arr[p] = q;
    
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0;i <= n;i++){
        arr[i] = i;
    }
    int ans = 0;
    for(int i = 0;i < m;i++){
        int p, q;
        cin >> p >> q;
        if(srch(p) == srch(q)){
            ans += 1;
        }
        else{
            comb(p, q);
        }
    }
    set<int> s;
    for(int i = 1;i <= n;i++){
        s.insert(srch(i));
    }
    ans += s.size()-1;
    cout << ans;
}