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
    mstack[0] = arr[n].second;
    idxstack[0].first = arr[n].first;
    idxstack[0].second = n;
    ll minlen = -1;
    for(ll i = n-1;i >= 0;i--){
        if(arr[i].second > mstack[idx-1]){
            mstack[idx] = arr[i].second;
            idxstack[idx].first = arr[i].first;
            idxstack[idx].second = i;
            idx++;
        }

        /*
        cout << "m: ";
        for(int i = 0;i < idx;i++){
            cout << mstack[i] << " ";
        }
        cout << endl;
        */

        ll it = lower_bound(&mstack[0], &mstack[idx], arr[i+1].second) - &mstack[0];
        if((idxstack[it].second - (i))%2 == 1){
            it++;
        }
        //cout << "i: " << i << " " << it << endl;
        if(it >= idx || it < 0) continue;
        ll len = idxstack[it].first - arr[i+1].first;
        //cout << arr[i].second << " " << arr[i].first << " " << idxstack[lo] << "\n";
        //cout << idxstack[it].first << " " << arr[i+1].first << " " << arr[i].first << " " << arr[i].second << "\n";
        if(len > minlen){

            minlen = len;
        }
    }
    cout << minlen;

}
