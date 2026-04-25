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
    if(a.beg == b.beg) return a.y > b.y;
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
        ll b = (0-p)*r;
        ll f = b+r;
        v.push_back({b, q, 1});
        v.push_back({f, q, -1});
    }
    sort(v.begin(), v.end(), comp);
    /*
    for(int i = 0;i < v.size();i++){
        cout << v[i].beg << " " << v[i].ent << " " << v[i].y << "\n";
    }
    */
    set<ll> s;
    for(int i = 0;i < n*2;){
        //cout << i << " ";
        //cout << "loop";
        for(int j = i;j <= n*2;j++){
            //cout << "loop";
            if(v[j].beg != v[i].beg || j == n*2){
                i = j;
                break;
            }
            if(v[j].ent == 1){
                s.insert(v[j].y);
            }
            else{
                s.erase(v[j].y);
            }
        }
        if(s.size() > 0){
            ans[*s.begin()] = 1;
        }
    }
    int cnt = 0;
    for(ll i = 0;i <= 1000000;i++){
        if(ans[i] == 1){
            cnt++;
        }
    }
    cout << cnt;
}
