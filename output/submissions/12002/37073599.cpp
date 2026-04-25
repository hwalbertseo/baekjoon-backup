#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

struct coo{
    ll x;
    ll y;
};

coo arr[50005];
ll coox[50005];
ll cooy[50005];

int main()
{
    ll n;
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        arr[i] = {p, q};
        coox[i] = p;
        cooy[i] = q;
    }
    sort(coox, coox+n);
    sort(cooy, cooy+n);
    ll mincoo = 2147483647;
    for(ll i = 0;i <= 3;i++){
        for(ll j = 0;j <= 3;j++){
            for(ll r = n-1;r > n-4;r--){
                for(ll w = n-1;w>n-4;w--){
                    ll x1 = coox[i];
                    ll y1 = cooy[j];
                    ll x2 = coox[r];
                    ll y2 = cooy[w];
                    if(x1 > x2 || y1 > y2){
                        continue;
                    }
                    ll outsidecnt = 0;
                    for(ll k = 0;k < n;k++){
                        if(arr[k].x < x1){
                            outsidecnt++;
                        }
                        else if(arr[k].x > x2){
                            outsidecnt++;
                        }
                        else if(arr[k].y < y1){
                            outsidecnt++;
                        }
                        else if(arr[k].y > y2){
                            outsidecnt++;
                        }
                    }
                    if(outsidecnt <= 3){
                        ll area = (x2-x1) * (y2-y1);
                        if(area < mincoo){
                            mincoo = area;
                        }
                    }
                }
            }
        }
    }
    cout << mincoo;
}
