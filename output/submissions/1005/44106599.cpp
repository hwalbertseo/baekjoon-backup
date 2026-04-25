#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

ll n, k, target;
ll ind[1005];
ll time[1005];
ll dp[1005];

void init(){
    n = 0;
    k = 0;
    target = 0;
    for(int i= 0;i < 1005;i++){
        ind[i] = 0;
        time[i] = 0;
        dp[i] = 0;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll tc;
    cin >> tc;
    for(ll ii = 0;ii < tc;ii++){
        init();
        vector<ll> graph[1005];
        cin >> n >> k;
        for(ll i = 1;i <= n;i++){
            cin >> time[i];
        }
        for(ll i = 0;i < k;i++){
            ll p, q;
            cin >> p >> q;
            graph[p].push_back(q);
            ind[q]++;
        }
        cin >> target;

        //topsort
        queue<ll> q;
        for(ll i = 1;i <= n;i++){
            if(ind[i] == 0){
                q.push(i);
                dp[i] = time[i];
            }
        }
        while(!q.empty()){
            ll cur = q.front();
            ll tim = dp[cur];
            q.pop();
            for(ll i = 0;i < graph[cur].size();i++){
                ll nxt = graph[cur][i];
                ind[nxt]--;
                dp[nxt] = max(tim+time[nxt], dp[nxt]);
                if(ind[nxt] == 0){
                    q.push(nxt);
                }
            }
            /*
            cout << "dp: \n";
            for(int i = 1;i <= n;i++){
                cout << dp[i] << " ";
            }
            cout << endl;
            */
        }
        cout << dp[target] << "\n";
    }
}
