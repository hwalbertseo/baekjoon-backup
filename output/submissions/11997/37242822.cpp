#include <iostream>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

ll n;

struct coo{
    int x;
    int y;
};

coo mem[1005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(ll i = 0;i < n;i++){
        ll p, q;
        cin >> p >> q;
        mem[i] = {p, q};
    }
    ll minarea = 2e9;

    for(int i = 0;i < n;i++){
        int dx[4] = {-1, -1, 1, 1};
        int dy[4] = {-1, 1, 1, -1};
        for(int j = 0;j < 4;j++){
            int px = mem[i].x + dx[j];
            int py = mem[i].y + dy[j];
            int ar1 = 0;
            int ar2 = 0;
            int ar3 = 0;
            int ar4 = 0;
            for(int k = 0;k < n;k++){
                if(mem[k].x < px && mem[k].y < py){
                    ar1++;
                }
                else if(mem[k].x < px && mem[k].y > py){
                    ar2++;
                }
                else if(mem[k].x > px && mem[k].y < py){
                    ar3++;
                }
                else if(mem[k].x > px && mem[k].y > py){
                    ar4++;
                }
            }
            int area = max(max(ar1, ar2), max(ar3, ar4));
            if(area < minarea){
                minarea = area;
            }
        }
    }
    cout << minarea;
}
