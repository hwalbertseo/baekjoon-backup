#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[100000];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    ll sum = 0;
    for(ll i = 1;i <= n;i++){
        cin >> arr[i];
        sum += arr[i];
    }
    ll ans = 0;
    ans += sum*2;
    ans += n*2;
    for(ll i = 1;i <= n;i++){
        ll zero = 0;
        ll left = max(zero, arr[i] - arr[i-1]);
        ll right = max(zero, arr[i] - arr[i+1]);
        ans += left + right;
    }
    cout << ans;  
}