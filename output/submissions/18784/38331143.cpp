#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#define ll long long

using namespace std;

struct point{
    ll x, y, sum;
};

vector<ll> x[200005];
vector<ll> y[200005];
point arr[100005];
ll mod = 1e9 + 7;

bool comp1(point a, point b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    else{
        return a.x < b.x;
    }
}

bool comp2(point a, point b){
    if(a.y == b.y){
        return a.x < b.x;
    }
    else{
        return a.y < b.y;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    //freopen("triangles.in", "r", stdin);
    //freopen("triangles.out", "w", stdout);
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        p += 10000;
        q += 10000;
        x[p].push_back(q);
        y[q].push_back(p);
        arr[i] = {p, q, 0};
    }
    sort(arr, arr+n, comp1);
    ll pastx = -1;
    ll pasty = -1;
    ll gone = 0;
    ll pastsum = 0;
    for(ll i = 0;i < n;i++){
        ll xx = arr[i].x;
        if(x[xx].size() < 2){
            continue;
        }
        if(xx == pastx){
            gone++;
            ll dif = abs(pasty - arr[i].y);
            ll sum = pastsum + (gone*dif);
            sum -= (x[xx].size()-gone)*dif;
            arr[i].sum = sum;
            pasty = arr[i].y;
            pastsum = sum;
            //cout << sum << "/s/";
        }
        else{
            gone = 0;
            pastx = xx;
            pasty = arr[i].y;
            pastsum = 0;
            for(ll j = i;j < i+(x[xx].size());j++){
                pastsum += abs(arr[i].y-arr[j].y);
            }
            arr[i].sum = pastsum;
            //cout << pastsum << "/p/";
        }
        //cout << arr[i].x-10000 << " " << arr[i].y-10000 << endl;
    }
    //cout << "\n";
    pastx = -1;
    pasty = -1;
    gone = 0;
    pastsum = 0;
    sort(arr, arr+n, comp2);
    for(ll i = 0;i < n;i++){
        ll yy = arr[i].y;
        if(y[yy].size() < 2){
            continue;
        }
        if(yy == pasty){
            gone++;
            ll dif = abs(pastx - arr[i].x);
            ll sum = pastsum + (gone*dif);
            sum -= (y[yy].size()-gone)*dif;
            ans += arr[i].sum * sum;
            pastx = arr[i].x;
            pastsum = sum;
            //cout << sum << "/s/";
        }
        else{
            gone = 0;
            pastx = arr[i].x;
            pasty = yy;
            pastsum = 0;
            for(ll j = i;j < i+(y[yy].size());j++){
                pastsum += abs(arr[i].x-arr[j].x);
            }
            ans += arr[i].sum * pastsum;
            //cout << pastsum << "/p/";
        }
        //cout << arr[i].x-10000 << " " << arr[i].y-10000 << " " << arr[i].sum << endl;
        ans %= 1000000007;
    }
    cout << ans;
}
/*
9
-2 1
1 3
1 2
1 1
1 0
1 -1
1 -2
2 1
3 1
*/
