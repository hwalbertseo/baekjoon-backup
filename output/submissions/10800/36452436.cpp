#include <iostream>
#include <map>
#include <algorithm>
#define ll long long

using namespace std;

struct ball{
    ll index;
    ll c;
    ll s;
};

ball arr[200002];
ll cnt[200002];
ll edible[200002];
ll stacksize;

bool comp(ball a, ball b){
    return a.s < b.s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1;i <= n;i++){
        cin >> arr[i].c >> arr[i].s;
        arr[i].index = i;
    }
    sort(arr+1, arr+n+1, comp);
    for(ll i = 1;i <= n;){
        ll last;
        for(ll j = i;j<=n+1;j++){
            if(arr[j].s != arr[i].s || j >= n+1){
                last = j;
                break;
            }
            edible[arr[j].index] = stacksize - cnt[arr[j].c];
        }
        for(ll j = i;j < last;j++){
            stacksize += arr[j].s;
            cnt[arr[j].c] += arr[j].s;
        }
        i = last;
    }
    for(ll i = 1;i <= n;i++){
        cout << edible[i] << "\n";
    }
}
