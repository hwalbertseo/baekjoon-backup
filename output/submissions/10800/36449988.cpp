#include <iostream>
#include <map>
#include <algorithm>
#define ll long long

using namespace std;

struct ball{
    ll index;
    ll c;
    ll s;
};

ball arr[200002];
ll cnt[200002];
ll edible[200002];
ll stacksize[200002];

bool comp(ball a, ball b){
    return a.s < b.s;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        cin >> arr[i].c >> arr[i].s;
        arr[i].index = i;
    }
    sort(arr, arr+n, comp);
    edible[arr[0].index] = 0;
    cnt[arr[0].c] += arr[0].s;
    stacksize[0] = arr[0].s;
    for(ll i = 1;i < n;){
        ll jcnt = 0;
        ll cumulstacksize = 0;
        map<ll , ll > cumulcolor;
        for(ll j = i;;j++){
            edible[arr[j].index] += stacksize[i-1] - cnt[arr[j].c];
            jcnt++;
            cumulstacksize += arr[j].s;
            cumulcolor[arr[j].c] += arr[j].s;
            stacksize[j] = stacksize[j-1] + arr[j].s;
            if(arr[j].s < arr[j+1].s || j == n-1) {
                for(auto it = cumulcolor.begin();it != cumulcolor.end();it++){
                    cnt[it->first] += it->second;
                }
                i+=jcnt;
                break;
            }
        }
    }
    for(ll i = 0;i < n;i++){
        cout << edible[i] << "\n";
    }
}
