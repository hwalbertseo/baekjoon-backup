#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#define ll long long

using namespace std;

struct cow{
    ll beg;
    ll y;
    int ent;
};

bool comp(cow a, cow b){
    return a.beg < b.beg;
}

int ans[1000005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    vector<cow> v;
    for(ll i = 0;i < n;i++){
        ll p, q, r;
        cin >> p >> q >> r;
        p++;
        int b = (0-p)*r;
        int f = b+r;
        v.push_back({b, r, 1});
        v.push_back({f, r, -1});
    }
    sort(v.begin(), v.end(), comp);
    set<int> s;
    for(int i = 0;i < n*2;i++){
        if(v[i].ent == 1){
            s.insert(v[i].y);
        }
        else{
            s.erase(v[i].y);
        }
        if(s.size() > 0){
            ans[*s.begin()] = 1;
        }
    }
    int cnt = 0;
    for(int i = 0;i <= 1000000;i++){
        if(ans[i] == 1){
            cnt++;
        }
    }
    cout << cnt;
}
