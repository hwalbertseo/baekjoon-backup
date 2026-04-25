#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}


pair<int, int> arr[50005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, d;
    cin >> n >> d;
    for(int i = 0;i < n;i++){
        int p, q;
        cin >> p >> q;
        arr[i] = {p, q};
    }
    sort(arr, arr+n, comp);
    set<int> s;
    int j = 0;
    int cnt = 0;
    for(int i = 0;i < n;i++){
        for(;arr[j].second >= arr[i].second*2;j++){
            s.insert(arr[j].first);
        }
        if(s.empty() || s.size() == 1){
            continue;
        }
        else{
            auto lower = s.lower_bound(arr[i].first);
            auto higher = s.upper_bound(arr[i].first);
            if(lower == s.end() || higher == s.begin()){
                continue;
            }
            cnt++;
        }
    }
    cout << cnt;
}
