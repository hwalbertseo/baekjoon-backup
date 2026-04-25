#include <iostream>
#define ll long long

using namespace std;

ll ntom(ll n, ll m){
    ll ans = 1;
    for(ll i = n;i <= m;i++){
        ans *= i;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll p, q;
    cin >> p >> q;
    ll a = ntom(p-q+1, p);
    ll b = ntom(1, q);
    cout << a/b;
}
