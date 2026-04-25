#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; ++i)
#define REP(i, n) for (int i = 1; i <= n; ++i)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int mod = 1e9 + 7;
const int MAXN = 1e5;

struct mi {
    int v;
    mi(ll _v) : v(_v % mod) {
        v += (v < 0) * mod;
    }
    mi() : v(0) { }
    mi operator+(mi b) {
        return mi(v + b.v);
    }
    mi operator-(mi b) {
        return mi(v - b.v);
    }
    mi operator*(mi b) {
        return mi((ll)v * b.v);
    }
};

int N;

vector<vector<pii>> xyi;
vector<pii> xy;
vector<mi> ans[MAXN + 1];

void solve() {
    for (int i = 0; i <= 20000; ++i) {
        int len = xyi[i].size();
        if (len) {
            mi psum = 0;
            for (int j = 0; j < len; ++j) {
                psum = psum + xyi[i][j].first - xyi[i][0].first;
            }
            for (int j = 0; j < len; ++j) {
                if (j)
                    psum = psum + (2 * j - len) * (xyi[i][j].first - xyi[i][j - 1].first);
                ans[xyi[i][j].second].emplace_back(psum);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    xyi.resize(20001);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        xy.emplace_back(x, y);
        xyi[x + 10000].emplace_back(y, i);
    }
    solve();
    xyi.clear();
    xyi.resize(20001);
    rep(i, N) {
        auto [x, y] = xy[i];
        xyi[y + 10000].emplace_back(x, i);
    }
    solve();
    mi ret = 0;
    for (int i = 0; i < N; ++i) {
        ret = ret + ans[i][0] * ans[i][1];
    }
    cout << ret.v;
    return 0;
}