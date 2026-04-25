#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll orig[100005];
ll arr[100005];

ll solve(ll k, ll l, ll i){
    ll honey = 0;
    ll a = max(k, l);
    ll b = min(k, l);
    //cout << a << " " << b << " " << i << " ";
    honey += arr[max(a, i)] - arr[min(a, i)-1];
    honey += arr[max(b, i)] - arr[min(b, i)-1];
    //cout << honey << endl;
    honey -= orig[a];
    //cout << honey << endl;
    honey -= orig[b];
    //cout << honey << endl;
    if(a < i && b < i){
        honey -= orig[a];
    }
    else if(a > i && b > i){
        honey -= orig[b];
    }
    //cout << honey << endl;
    return honey;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1;i <= n;i++){
        cin >> orig[i];
    }
    for(ll i = 1;i <= n;i++){
        arr[i] = arr[i-1] + orig[i];
    }
    ll ans = -1;

    //벌벌꿀
    ll a1 = 1, a2;
    ll i = n;
    ll honey = 0;
    for(a2 = 2;a2 < i;a2++){
        honey = solve(a1, a2, i);
        if(honey > ans){
            ans = honey;
        }
    }

    //벌꿀벌
    a1 = 1;
    a2 = n;
    for(i = a1+1;i < n;i++){
        honey = solve(a1, a2, i);
        if(honey > ans){
            ans = honey;
        }
    }

    //꿀벌벌
    a1 = n;
    i = 1;
    for(a2 = i+1;a2 < a1;a2++){
        honey = solve(a1, a2, i);
        if(honey > ans){
            ans = honey;
        }
    }
    cout << ans;
}
