// Online C++ compiler to run C++ program online
#include <iostream>
#define ll long long

using namespace std;

int main() {
    // Write C++ code here
    ll n, m;
    cin >> n >> m;
    ll cnt = 0;
    for(ll i = n;i <= m;i++){
        ll beg = 1;
        for(ll j = 0;j < 64;j++){
            ll res = i & beg;
            //cout << beg << " " << res << "\n";
            if(res == 0){
                beg = beg << 1;
                continue;
            }
            else{
                cnt += res;
                break;
            }
        }
    }
    cout << cnt;
    
}