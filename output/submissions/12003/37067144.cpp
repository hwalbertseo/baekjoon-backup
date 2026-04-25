#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

ll inp[50005];
ll arr[50005];

int main()
{
    ll n, k;
    cin >> n >> k;
    for(ll i = 0;i < n;i++){
        cin >> inp[i];
    }
    sort(inp, inp+n);
    ll j = 0;
    for(int i = 0;i < n;i++){
        while(inp[j] < inp[i]-k){
            j++;
        }
        arr[i] = j;
    }
    j=0;
    ll mx = -1;
    ll mv = -1;
    for(ll i = 0;i < n;i++){
        while(j < arr[i]){
            ll p;
            p = j-arr[j]+1;
            if(p > mx) mx = p;
            j++;
        }
        if(i-arr[i] + mx + 1 > mv){
            mv = i-arr[i] + mx + 1;
        }

    }
    cout << mv;

}
