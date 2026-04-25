#include <iostream>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

set<pair<ll, ll>, decltype(&comp)> s(&comp);
pair<ll, ll> arr[50005];
ll n, g, b, d;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> g >> b >> d;
    arr[0] = {0, 1e9};
    for(ll i = 1;i <= n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p, q};
    }
    sort(arr, arr+n);
    ll cur = b;
    ll one = 1, two = 1;
    arr[n+1] = {d, 1e9};
    ll ans = 0;
    ll no = 0;

    for(;no <= n;){
        if(no == 0){
            if(d - arr[no].first <=b){
                ans += max(arr[no].second*(d-arr[no].first - cur), 0ll);
                //cout << no << " " << d-arr[no].first << " " << arr[no].second << endl;
                cout << ans;
                return 0;
            }
            while(arr[two].first - arr[no].first <= b){
                s.insert({two, arr[two].second});
                two++;
                if(two > n){
                    break;
                }
            }
        }
        else{
            if(d - arr[no].first <= g){
                ans += max(arr[no].second*(d-arr[no].first - cur), 0ll);
                //cout << no << " " << d-arr[no].first << " " << arr[no].second << endl;
                cout << ans;
                return 0;
            }
            while(arr[two].first - arr[no].first <= g){
                s.insert({two, arr[two].second});
                two++;
                if(two > n){
                    break;
                }
            }
        }
        while(arr[one].first <= arr[no].first){
            s.erase({one, arr[one].second});
            one++;
            if(one > n){
                break;
            }
        }
        /*
        cout << no << " " << cur << " " << one << " " << two << endl;
        cout << "s: ";
        for(pair<ll, ll> temp : s){
            cout << temp.second << " ";
        }
        cout << endl;
        */
        if(one > two){
            cout << -1;
            return 0;
        }
        auto it = s.begin();
        ll needed;
        if((*it).second > arr[no].second){
            needed = max(g-cur,0ll);
            ans += needed*arr[no].second;
            //cout << "fir: " << no << " " << needed << " " << arr[no].second << endl;
            //cout << ans << endl;
        }
        else{
            needed = max(arr[(*it).first].first - arr[no].first - cur, 0ll);
            ans +=  needed * arr[no].second;
            //cout << "sec: " << no << " " << needed << " " << (*it).second << endl;
            //cout << ans << endl;
        }
        cur = cur + needed - (arr[(*it).first].first - arr[no].first);

        no = (*it).first;
    }
}
//C:\C++\CodeForces\5828\main.cpp|52|error: 'struct std::_Rb_tree_const_iterator<std::pair<long long int, long long int> >' has no member named 'first'|
