#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

pair<ll, ll> arr[100005];
ll mstack1[100005];
ll mstack2[100005];
pair<ll, ll> idxstack1[100005];
pair<ll, ll> idxstack2[100005];

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
    ll idx1 = 0;
    ll idx2 = 0;
    ll minlen = -1;
    for(ll i = n;i >= 0;i--){
        if(i%2 == 1){
            if(arr[i].second > mstack1[idx1-1] && arr[i].second > mstack2[idx2-1]){
                mstack1[idx1] = arr[i].second;
                idxstack1[idx1].first = arr[i].first;
                idxstack1[idx1].second = i;
                idx1++;
            }
            if(i == n){
                continue;
            }

            /*
            cout << "m: ";
            for(int i = 0;i < idx;i++){
                cout << mstack[i] << " ";
            }
            cout << endl;
            */

            ll it = lower_bound(&mstack1[0], &mstack1[idx1], arr[i+1].second) - &mstack1[0];
            //cout << "i: " << i << " " << it << endl;
            if(it >= idx1 || it < 0) continue;
            ll len = idxstack1[it].first - arr[i+1].first;
            //cout << arr[i].second << " " << arr[i].first << " " << idxstack[lo] << "\n";
            //cout << idxstack1[it].first << " " << arr[i+1].first << " " << arr[i].first << " " << arr[i].second << "\n";
            if(len > minlen){
                minlen = len;
            }
        }
        else{
            if(arr[i].second > mstack1[idx1-1] && arr[i].second > mstack2[idx2-1]){
                mstack2[idx2] = arr[i].second;
                idxstack2[idx2].first = arr[i].first;
                idxstack2[idx2].second = i;
                idx2++;
            }

            if(i == n){
                continue;
            }

            /*
            cout << "m: ";
            for(int i = 0;i < idx;i++){
                cout << mstack[i] << " ";
            }
            cout << endl;
            */

            ll it = lower_bound(&mstack2[0], &mstack2[idx2], arr[i+1].second) - &mstack2[0];
            //cout << "i: " << i << " " << it << endl;
            if(it >= idx2 || it < 0) continue;
            ll len = idxstack2[it].first - arr[i+1].first;
            //cout << arr[i].second << " " << arr[i].first << " " << idxstack[lo] << "\n";
            //cout << idxstack2[it].first << " " << arr[i+1].first << " " << arr[i].first << " " << arr[i].second << "\n";
            if(len > minlen){
                minlen = len;
            }
        }
    }
    cout << minlen;

}
