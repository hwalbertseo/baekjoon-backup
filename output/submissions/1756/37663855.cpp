#include <iostream>
#include <algorithm>
#include <set>
#define ll long long

using namespace std;

ll arr[300005];

bool comp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.first == b.first){
        return a.second > b.second;
    }
    else{
        return a.first < b.first;
    }
}

set<pair<ll, ll>, decltype(&comp)> s(&comp);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> arr[i];
        s.insert({arr[i], i});
    }
    int idx = n;
    int rec = n+1;
    for(int i = 1;i <= m;i++){
        ll p;
        cin >> p;
        pair<ll, ll> pa = {p-1, 0};
        auto it = s.lower_bound(pa);
/*
        //cout << p << " " << rec << endl;
        cout << "p: " << p << " " << (*it).first << " " << (*it).second << endl;
        for(auto pp = s.begin();pp != s.end();pp++){
            cout << (*pp).first << " ";
        }
        cout << endl;
        */
        if(it != s.end()){
            if(it == s.begin()){
                rec = rec-1;
            }
            else{
                it--;
                rec = (*it).second-1;
            }
        }
        else{
            rec = 0;
        }
        //cout << p << " " << rec << endl;
        for(int j = rec;j <= idx;j++){
            s.erase({arr[j], j});
        }
/*
        for(auto pp = s.begin();pp != s.end();pp++){
            cout << (*pp).first << " ";
        }
        cout << endl;
*/
        idx = rec;
    }
    cout << rec;
}
/*
7 3
5 6 4 3 6 2 3
1 1 1
*/
