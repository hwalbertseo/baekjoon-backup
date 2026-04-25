#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

ll arr[2000000];
ll ans[2000000];

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        cin >> arr[i];
    }
    ans[0] = arr[0];
    ll len = 1;
    for(ll i = 1;i < n;i++){
        ll cur = arr[i];
        if(cur > ans[len-1]){
            ans[len] = cur;
            len++;
        }
        else{
            ll idx = lower_bound(ans, ans+len, cur) - ans;
            ans[idx] = cur;
        }
        /*
        cout << cur << ": ";
        for(int j = 0;j < len;j++){
            cout << ans[j] << " ";
        }
        cout << "\n";
        */
    }
    cout << len;
}