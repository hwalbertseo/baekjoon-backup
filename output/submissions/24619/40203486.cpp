#include <iostream>
#include <set>
#include <vector>

using namespace std;

pair<int, int> arr[100005];
int cnt[100005];
int del[100005];

void init(){
    for(int i = 0;i < 100005;i++){
        cnt[i] = 0;
        del[i] = 0;
    }
}

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second){
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T;
    cin >> T;
    for(int ii =0;ii < T;ii++){
        int m, n, k;
        cin >> m >> n >> k;
        init();
        set<pair<int, int>, decltype(&comp)> val(&comp);
        set<pair<int, int>> ps;
        set<pair<int, int>> fil;

        for (int i = 1; i<=n; i++) {
            arr[i].first = i;
            cin >> arr[i].second;
            fil.insert(arr[i]);
            cnt[arr[i].second]++;
        }

        string ans = "YES\n";
        int t = 1;

        for(int i=1; i<=n; i++) {
            if(cnt[t] == 0) {
                t++;
                i--;
                continue;
            }
            int fl = 0;
            auto it = val.lower_bound({-1, t});
            while ((*it).second < t+k && it != val.end()) {
                cnt[(*it).second]--;
                del[(*it).first] = 1;
                ps.erase(*it);
                it = val.erase(it);
                fl = 1;
            }
            if (fl) {
                i--;
                continue;
            }
            ps.insert(arr[i]);
            val.insert(arr[i]);
            if (ps.size() > k) {
                pair<int, int> file = *ps.begin();
                val.erase(file);
                ps.erase(file);
            }
        }
        int idx = n;
        if (!ps.empty()){
            idx = ps.begin()->first;
        }
        for (;idx >= 1;idx--) {
            if (del[idx] == 1) continue;
            if (cnt[t] == 0) {
                t++;
                idx++;
                continue;
            }
            int fl = 0;
            auto it = val.lower_bound({-1, t});
            while ((*it).second < t+k && it != val.end()) {
                cnt[(*it).second]--;
                del[(*it).first] = 1;
                ps.erase(*it);
                it = val.erase(it);
                fl = 1;
            }
            if (fl == 1) {
                idx++;
                continue;
            }
            ps.insert(arr[idx]);
            val.insert(arr[idx]);
            if (ps.size() > k) {
                ans = "NO\n";
            }
        }
        cout << ans;

    }
}
