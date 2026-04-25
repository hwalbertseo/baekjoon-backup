#include <iostream>
#include <map>
#include <vector>
#define ll long long

using namespace std;

map<int, vector<int>> x;
map<int, vector<int>> y;
pair<int, int> arr[100005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    ll ans = 0;
    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        x[p].push_back(q);
        y[q].push_back(p);
        arr[i] = {p,q};
    }
    for(int i = 0;i < n;i++){
        ll xx = arr[i].first;
        ll yy = arr[i].second;
        if(x[xx].size() > 1 && y[yy].size() > 1){
            ll xsum = 0;
            ll ysum = 0;
            for(int j = 0;j < x[xx].size();j++){
                xsum += abs(x[xx][j] - xx);
            }
            for(int j = 0;j < y[yy].size();j++){
                ysum += abs(x[yy][j] - yy);
            }
            ans += xsum*ysum;
        }
    }
    cout << ans;
}
