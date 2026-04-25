#include <iostream>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    ll ans = 0;
    if(n % 2 == 0){
        ans = (n-2)*(n-2);
    }
    else{
        ans = (((n-1)/2)+1) * ((n-1)/2);
    }
    cout << ans;
}