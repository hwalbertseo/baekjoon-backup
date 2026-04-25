#include <iostream>
#define ll long long

using namespace std;

ll arr[300005];
ll ans[300005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        cin >> arr[i];
    }
    ll b = n;
    ll a = 1;
    for(ll i = 1;i <= m;i++){
        cin >> ans[i];
    }
    ll rec = 0;
    while(b >= 1 && a <= m){
        if(ans[a] < arr[b]){
            rec = b;
            a++;
        }
        b--;
    }
    cout << rec;
}
