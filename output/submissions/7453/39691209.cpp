#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll arr[16000001];
ll a1[4][4001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll j = 0;j < n;j++){
        for(ll i = 0;i < 4;i++){
            cin >> a1[i][j];
        }
    }
    ll idx = 0;
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j < n;j++){
            arr[idx] = a1[0][i] + a1[1][j];
            idx++;
        }
    }
    //cout << idx;
    sort(arr, arr+idx);
    ll cnt = 0;
    for(ll i = 0;i < n;i++){
        for(ll j = 0;j < n;j++){
            ll ans = a1[2][i] + a1[3][j];
            ll lb = lower_bound(&arr[0], &arr[idx], -ans) - &arr[0];
            if(arr[lb] + ans == 0){
                ll ub = upper_bound(&arr[0], &arr[idx], -ans) - &arr[0];
                cnt += ub-lb;
            }
        }
    }
    cout << cnt;
}
