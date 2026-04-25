#include <iostream>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

ll arr[5005];
ll save[12500005];
multiset<ll> s;
pair<ll, ll> saved[12500005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    ll nxt = 0;
    for(ll i = 0;i < n;i++){
        for(ll j = i+1;j < n;j++){
            save[nxt] = arr[i]+arr[j];
            saved[nxt] = {arr[i], arr[j]};
            nxt++;
        }
    }
    ll m[3];
    ll mi = 9e17;
    for(ll i = 0;i < nxt;i++){
        s.erase(s.find(saved[i].first));
        s.erase(s.find(saved[i].second));

        auto it = s.lower_bound(-save[i]);
        if(it == s.end()){
            it--;
        }
        else if(it == s.begin()){
            it++;
        }
        ll temp1 = abs((*it) + save[i]);
        ll temp2 = abs((*(--it)) + save[i]);
        //cout << temp1 << " " << temp2 << endl;
        ll temp;
        if(temp1 < temp2){
            it++;
            temp = temp1;
        }
        else{
            temp = temp2;
        }
        if(temp < mi){
            mi = temp;
            m[0] = saved[i].first;
            m[1] = saved[i].second;
            m[2] = *it;
        }

        s.insert(saved[i].first);
        s.insert(saved[i].second);
    }
    sort(m, m+3);
    cout << m[0] << " " << m[1] << " " << m[2];
}
