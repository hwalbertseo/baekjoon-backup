#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

pair<ll, ll> arr[100005];
ll mstack[100005];
pair<ll, ll> idxstack[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 1;i <= n;i++){
        ll p;
        char q;
        cin >> p >> q;
        if(q == 'W'){
            arr[i] = {p, 1};
        }
        else{
            arr[i] = {p, -1};
        }
    }
    sort(arr+1, arr+n+1);

    for(ll i = 1;i <= n;i++){
        arr[i].second = arr[i-1].second + arr[i].second;
        //cout << arr[i].second << " ";
    }

    //cout <<endl;
    ll idx = 1;
    mstack[0] = arr[1].second;
    idxstack[0].first = arr[1].first;
    idxstack[0].second = 1;
    ll minlen = -1;
    for(ll i = 2;i <= n;i++){
        if(arr[i].second < mstack[idx-1]){
            mstack[idx] = arr[i].second;
            idxstack[idx].first = arr[i].first;
            idxstack[idx].second = i;
            idx++;
        }
        ll hi = idx-1;
        ll lo = 0;
        while(lo < hi){
            ll mid = (hi+lo)/2;
            if(mstack[mid] > arr[i].second){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        ll len = arr[i].first-idxstack[lo].first;
        //cout << arr[i].second << " " << arr[i].first << " " << idxstack[lo] << "\n";
        if(len > minlen && (i-idxstack[lo].second)%2 == 1){
            minlen = len;
        }
    }
    cout << minlen;

}
