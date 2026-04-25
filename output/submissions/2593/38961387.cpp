#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> floor[100005];
vector<int> elevator[105];
bool visit[105];
bool visitflr[100005];
bool pre[105];
queue<int> q;
vector<int> path;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= m;i++){
        int p, q;
        cin >> p >> q;
        for(int j = p;j <= n;j += q){
            floor[j].push_back(i);
            elevator[i].push_back(j);
        }
    }
    int s, f;
    cin >> s >> f;
    for(int i = 0;i < floor[s].size();i++){
        q.push(floor[s][i]);
    }
    int last;
    while(1){
        if(q.empty()){
            cout << -1;
            return 0;
        }
        int cur = q.front();
        //cout << cur << "\n";
        visit[cur] = 1;
        q.pop();
        bool brk = false;
        for(int i = 0;i < elevator[cur].size();i++){
            int flr = elevator[cur][i];
            //cout << "f: " << flr << "\n";
            if(flr == f){
                last = cur;
                brk = true;
                break;
            }
            if(visitflr[flr] == 1){
                continue;
            }
            for(int j = 0;j < floor[flr].size();j++){
                int elev = floor[flr][j];
                if(visit[elev] == 1){
                    continue;
                }
                //cout << "p2";
                visitflr[flr] = 1;
                pre[elev] = cur;
                //cout << elev << " " << cur << " \n";
                q.push(elev);
            }
        }
        if(brk){
            break;
        }
    }
    int ans = last;
    while(1){
        if(ans == 0){
            break;
        }
        path.push_back(ans);
        ans = pre[ans];
    }
    cout << path.size() << "\n";
    for(int i = path.size()-1;i >= 0;i--){
        cout << path[i] << "\n";
    }
}
