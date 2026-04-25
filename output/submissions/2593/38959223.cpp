#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> floor[100005];
vector<int> elevator[105];
int visit[105];
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
    while(1){
        int cur = q.front();
        visit[cur] = 1;
        path.push_back(cur);
        q.pop();
        for(int i = 0;i < elevator[cur].size();i++){
            int flr = elevator[cur][i];
            if(flr == f){
                goto finish;
            }
            for(int j = 0;j < floor[flr].size();j++){
                int elev = floor[flr][j];
                if(visit[elev]){
                    continue;
                }
                q.push(elev);
            }
        }
    }
    finish:
        for(int i =0 ;i < path.size();i++){
            cout << path[i] << " ";
        }
}
