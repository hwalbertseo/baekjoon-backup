#include <iostream>
#include <vector>
#include <queue>
#define ll long long

using namespace std;

ll n, m;
vector<ll> floor[100005];
vector<ll> elevator[105];
bool visit[105];
bool visitflr[100005];
ll pre[105];
queue<pair<ll, ll>> q;
vector<ll> path;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(ll i = 1;i <= m;i++){
        ll p, q;
        cin >> p >> q;
        for(ll j = p;j <= n;j += q){
            floor[j].push_back(i);
            elevator[i].push_back(j);
        }
    }
    ll s, f;
    cin >> s >> f;
    for(ll i = 0;i < floor[s].size();i++){
        //cout << floor[s][i] << "\n";
        q.push({floor[s][i], 0});
    }
    visitflr[s] = 1;
    ll last;
    while(1){
        if(q.empty()){
            cout << -1;
            return 0;
        }
        ll cur = q.front().first;
        if(visit[cur] == 1){
            q.pop();
            continue;
        }
        //cout << "c: " << cur << " " << q.size() << "\n";
        pre[cur] = q.front().second;
        visit[cur] = 1;
        q.pop();
        bool brk = false;
        for(ll i = 0;i < elevator[cur].size();i++){
            ll flr = elevator[cur][i];
            //cout << "f: " << flr << "\n";
            if(flr == f){
                last = cur;
                brk = true;
                break;
            }
            if(visitflr[flr] == 1){
                continue;
            }
            visitflr[flr] = 1;
            for(int j = 0;j < floor[flr].size();j++){
                ll elev = floor[flr][j];
                if(visit[elev] == 1){
                    continue;
                }
                //cout << "p2";
                //cout << elev << " " << cur << " \n";
                q.push({elev, cur});
            }
        }
        if(brk){
            break;
        }
    }
    ll ans = last;
    while(1){
        if(ans == 0){
            break;
        }
        path.push_back(ans);
        ans = pre[ans];
    }
    cout << path.size() << "\n";
    for(ll i = path.size()-1;i >= 0;i--){
        cout << path[i] << "\n";
    }
}
/*
20 4
2 5
4 8
1 8
7 5
1 12
*/
