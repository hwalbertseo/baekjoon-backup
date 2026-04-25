#include <iostream>
#include <queue>

using namespace std;

int p, r;
queue<pair<int, int>> q;
int dp[200005];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> p >> r;
    int time = 2e9;
    q.push({p, 0});
    int cnt = 0;
    for(int i = 0;i < 200005;i++){
        dp[i] = 2e9;
    }
    while(!q.empty()){
        int cur = q.front().first;
        int t = q.front().second;
        q.pop();
        if(dp[cur] < t){
            continue;
        }
        dp[cur] = t;
        //if(t == 4) cout << cur << " ";
        if(t > time){
            break;
        }
        if(t == time && cur == r){
            cnt++;
        }
        else if(cur == r){
            time = t;
            cnt++;
        }
        //cout << cur << " ";

        q.push({cur-1, t+1});
        q.push({cur+1, t+1});
        if(cur*2 < 200000)
            q.push({cur*2, t+1});
    }
    //cout << endl;
    cout << time << "\n" << cnt;
}
