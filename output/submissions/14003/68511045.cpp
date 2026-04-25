#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

ll arr[2000000];
ll ans[2000000];
ll rec[2000000];
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main(){
    //ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        cin >> arr[i];
    }
    ans[0] = arr[0];
    ll len = 1;
    rec[0] = 1;
    for(ll i = 1;i < n;i++){
        ll cur = arr[i];
        if(cur > ans[len-1]){
            ans[len] = cur;
            len++;
            rec[i] = len-1;
        }
        else{
            ll idx = lower_bound(ans, ans+len, cur) - ans;
            ans[idx] = cur;
            rec[i] = idx;
        }
        /*
        cout << cur << ": ";
        for(int j = 0;j < len;j++){
            cout << ans[j] << " ";
        }
        cout << "\n";
        */
    }
    cout << len << "\n";
    int find = len-1;
    for(ll i = n-1;i >= 0;i--){
        if(rec[i] == find){
            pq.push(arr[i]);
            find--;
        }
    }
    while(!pq.empty()){
        cout << pq.top() << " ";
        pq.pop();
    }
}
/*
16
-60 -41 -100 8 -8 -52 -62 -61 -76 -52 -52 14 -11 -2 -54 46 
*/