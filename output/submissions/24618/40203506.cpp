#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

struct coo{
    ll first, second, num;
};

bool comp(coo a, coo b){
    if(a.first == b.first){
        if(a.second == b.second){
            return a.num < b.num;
        }
        return a.second < b.second;
    }
    return a.first < b.first;
}

pair<ll, ll> arr[45];
vector<coo> v;
vector<coo> v2;
vector<coo> v3;
ll ans[45];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    ll xg, yg;
    cin >> xg >> yg;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p,q};
    }
    coo temp;
    temp.first = 0;
    temp.second = 0;
    temp.num = 0;
    v.push_back(temp);
    for(ll i = 0;i<n/2+1;i++){
        ll e = v.size();
        for(ll j = 0;j < e;j++){
            temp.first = v[j].first + arr[i].first;
            temp.second = v[j].second + arr[i].second;
            temp.num = v[j].num + 1;
            v.push_back(temp);
        }
    }
    sort(v.begin(), v.end(), comp);
    /*
    cout << v.size() << "\n";
    for(ll i = 0;i < v.size();i++){
        cout << v[i].first << " " << v[i].second << " " << v[i].num << "\n";
    }
    */
    temp.first = 0;
    temp.second = 0;
    temp.num = 0;
    v2.push_back(temp);
    for(ll i = n/2+1;i<n;i++){
        ll e = v2.size();
        for(ll j = 0;j < e;j++){
            temp.first = v2[j].first + arr[i].first;
            temp.second = v2[j].second + arr[i].second;
            temp.num = v2[j].num + 1;
            v2.push_back(temp);
        }
    }
    /*
    cout << v2.size() << "\n";
    for(ll i = 0;i < v2.size();i++){
        cout << v2[i].first << " " << v2[i].second << " " << v2[i].num << "\n";
    }
    */
    for(ll i = 0;i < v2.size();i++){
        coo now;
        now.first = xg-v2[i].first;
        now.second = yg-v2[i].second;
        now.num = 0;
        ll lb = lower_bound(v.begin(), v.end(), now, comp) - v.begin();
        /*
        cout << endl;
        cout << v[lb].first << " " << v[lb].second << "\n";
        cout << v2[i].first << " " << v2[i].second << "\n";
        */
        if(v[lb].first+v2[i].first == xg && v[lb].second + v2[i].second == yg){
            now.num = 2e9;
            ll ub = upper_bound(v.begin(), v.end(), now, comp) - v.begin();
            coo answer;
            answer.first = lb;
            answer.second = ub;
            answer.num = v2[i].num;
            v3.push_back(answer);
        }
    }
    for(ll i = 0;i < v3.size();i++){
        ll lb = v3[i].first;
        ll ub = v3[i].second;
        ll num = v3[i].num;
        for(ll j = lb;j < ub;j++){
            ans[v[j].num+num]++;
        }
    }
    for(ll i = 1;i <= n;i++){
        cout << ans[i] << "\n";
    }
}
