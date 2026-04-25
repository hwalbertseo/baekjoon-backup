#include <iostream>
#include <cmath>

#define ll long long

using namespace std;

ll arr[10005];
ll psum[10005];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    ll cnt = 0;
    for(ll i = 1;i <= n;i++){
        cin >> arr[i];
    }
    ll idx = 0;
    for(ll i = 1;i <= n;i++){
        psum[i] = psum[i-1] + arr[i];
    }
    ll add = psum[n];
    for(ll i = 1;i <= n;i++){
        ll cur = psum[i];
        for(ll j = 1;j <= n;j++){
            ll now = psum[j];
            if(now < cur){
                ll target = ceil((double) (cur-now) / (double) add);
                if(j < i){
                    cnt += target - 1;
                }
                else{
                    cnt += target;
                }
            }
            else{
                continue;
            }
        }
    }
    cout << cnt;
}