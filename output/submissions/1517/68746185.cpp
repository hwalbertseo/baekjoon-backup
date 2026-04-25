#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

ll arr[1000000];
vector<int> v;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        cin >> arr[i];
    }
    v.push_back(arr[n-1]);
    if(n == 1){
        cout << 0;
        return 0;
    }
    else if(n == 2){
        if(arr[0] < arr[1]){
            cout << 0;
        }
        else{
            cout << 1;
        }
        return 0;
    }
    ll ans = 0;
    for(ll i = n-2;i >= 0;i--){
        ll cur = arr[i];
        auto it = lower_bound(v.begin(), v.end(), cur);
        v.insert(it, cur);
        ll idx = it - v.begin();
        ans += idx;
/*
        for(ll j = 0;j < v.size();j++){
            cout << v[j] << " ";
        }
        cout << "\n" << idx << " " << ans << "\n";
*/
    }
    cout << ans;
}