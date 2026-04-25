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
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("moop.in", "r", stdin);
    //freopen("moop.out", "w", stdout);
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p,q};
    }
    sort(arr, arr+n);
    //cout << "\n";
    for(ll j = 0;j < n;j++){
        ll i = arr[j].second;
        if(s.size() == 0){
            s.push(i);
        }
        else{
            ll m = i;
            while(!s.empty()){
                ll hi = s.top();
                if(hi < m){
                    m = hi;
                }
                if(hi > i){
                    break;
                }
                else{
                    s.pop();
                }
            }
            s.push(m);
        }
        //cout << s.size() << " " << s.top() << "\n";
    }
    cout << s.size();
}
/*
10
-4 4
-3 3
-2 2
-1 1
0 2
1 3
2 4
3 3
4 2
5 1
*/
