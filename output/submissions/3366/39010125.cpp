#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

int main()
{
    ll n;
    cin >> n;
    ll before;
    cin >> before;
    ll ans = 0;
    for(ll i = 1;i < n;i++){
        ll now;
        cin >> now;
        ans += max(now,before);
    }
    cout << ans;
}
