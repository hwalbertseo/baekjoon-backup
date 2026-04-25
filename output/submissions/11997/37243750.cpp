#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#define ll long long

using namespace std;

ll n;

struct coo{
    int x;
    int y;
};

coo c[1005];
set<ll> memx;
set<ll> memy;
ll arr[1005][1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        memx.insert(p);
        memy.insert(q);
        c[i] = {p,q};
    }
    map<ll,ll> mapx;
    map<ll,ll> mapy;
    ll icnt = 1;
    for(auto it = memx.begin();it != memx.end();it++){
        mapx[*it] = icnt++;
    }
    ll jcnt = 1;
    for(auto it2 = memy.begin();it2 != memy.end();it2++){
        mapy[*it2] = jcnt++;
    }
    for(ll i = 0;i < n;i++){
        ll p = c[i].x;
        ll q = c[i].y;
        arr[mapx[p]][mapy[q]] = 1;
    }
    for(ll i = 1;i <= 1001;i++){
        for(ll j = 1;j <= 1001;j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1] + arr[i][j];
        }
    }
    ll minarea = 2e9;
    ll maxx = mapx.size();
    ll maxy = mapy.size();

    for(auto it = memx.begin();it != memx.end();it++){
        for(auto it2 = memy.begin();it2 != memy.end();it2++){
            ll p = mapx[*it];
            ll q = mapy[*it2];
            ll area = -1;
            //cout << p <<" " << q << endl;
            area = max(area, arr[p-1][q-1] - arr[p-1][0] - arr[0][q-1] + arr[0][0]);
            //cout << arr[p-1][q-1] - arr[0][0] << " ";
            area = max(area, arr[p-1][maxy] -arr[p-1][q-1] - arr[0][maxy] + arr[0][q-1]);
            //cout << arr[p-1][maxy] - arr[0][q-1] << " " ;
            area = max(area, arr[maxx][q-1] - arr[maxx][0] - arr[p-1][q-1] + arr[p-1][0]);
            //cout << arr[maxx][q-1] - arr[p-1][0] << " ";
            area = max(area, arr[maxx][maxy] - arr[maxx][q-1] - arr[p-1][maxy] + arr[p-1][q-1]);
            //cout << arr[maxx][maxy] - arr[p-1][q-1] << endl;
            if(area < minarea){
                minarea = area;
            }
        }
    }
    cout << minarea;
}
