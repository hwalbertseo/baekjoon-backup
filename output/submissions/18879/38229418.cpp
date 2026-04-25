#include <iostream>
#include <stack>
#include <algorithm>
#include <cstdio>
#define ll long long

using namespace std;

ll n;
pair<ll, ll> arr[100005];
stack<ll> s;

int main()
{
    //freopen("moop.in", "r", stdin);
    //freopen("moop.out", "w", stdout);
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p,q};
    }
    sort(arr, arr+n);
    for(ll j = 0;j < n;j++){
        ll i = arr[j].second;
        if(s.size() == 0){
            s.push(i);
        }
        else if(s.size() == 1){
            if(i < s.top()){
                s.push(i);
            }
            else{
                s.pop();
                s.push(i);
            }
        }
        else{
            ll m = i;
            while(!s.empty()){
                ll hi = s.top();
                if(hi < m){
                    m = hi;
                }
                if(hi > i){
                    s.push(m);
                    break;
                }
                else{
                    s.pop();
                }
            }
        }
    }
    cout << s.size();
    /*
    11
    -2 3
    -1 2
    0 1
    1 2
    2 3
    3 2
    4 1
    5 2
    6 3
    7 2
    8 1
    */
}
