#include <iostream>
#include <stack>
#include <algorithm>
#define ll long long

using namespace std;

ll n;
pair<ll, ll> arr[100005];
stack<ll> s;

int main()
{
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
            ll two = s.top();
            s.pop();
            ll one = s.top();
            s.pop();
            if(i >= one && i >= two){
                s.push(two);
            }
            else if(i < one && i>=two){
                s.push(one);
                s.push(two);
            }
            else{
                s.push(one);
                s.push(two);
                s.push(i);
            }
        }
    }
    cout << s.size();
}
